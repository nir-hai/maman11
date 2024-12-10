#include <stdio.h>

/* Constants */
#define ASCII_OFFSET 32          /* Difference between uppercase and lowercase */
#define LOWERCASE_A 'a'
#define LOWERCASE_Z 'z'
#define UPPERCASE_A 'A'
#define UPPERCASE_Z 'Z'
#define DIGIT_0 '0'
#define DIGIT_9 '9'

/* Helper Functions */
int is_lowercase(int ch) {
    return ch >= LOWERCASE_A && ch <= LOWERCASE_Z;
}

int is_uppercase(int ch) {
    return ch >= UPPERCASE_A && ch <= UPPERCASE_Z;
}

int is_digit(int ch) {
    return ch >= DIGIT_0 && ch <= DIGIT_9;
}

int main(void) {
    int current_char;
    int capitalized = 1; /* Indicates whether to capitalize the next letter */

    printf("Please enter a text. Note that sentence ends in '.' character\n");

    while ((current_char = getchar()) != EOF) {
        if (current_char == '.') {
            /* Handle the end of a sentence */
            putchar(current_char);
            capitalized = 1; /* The next letter should be capitalized */
        } else if (is_lowercase(current_char) && capitalized) {
            /* Capitalize lowercase at the beginning of a sentence */
            putchar(current_char - ASCII_OFFSET);
            capitalized = 0; /* Reset the capitalization flag */
        } else if (current_char == '"') {
            /* Handle quoted text */
            putchar(current_char);
            while ((current_char = getchar()) != '"' && current_char != EOF) {
                if (is_lowercase(current_char)) {
                    putchar(current_char - ASCII_OFFSET); /* Capitalize inside quotes */
                } else if (!is_digit(current_char)) {
                    putchar(current_char);
                }
            }
            if (current_char == '"') {
                putchar(current_char); /* Print the closing quote */
            }
        } else if (is_uppercase(current_char)) {
            /* Convert uppercase to lowercase unless it's the start of a sentence */
            if (capitalized) {
                putchar(current_char); /* Keep uppercase */
                capitalized = 0;       /* Reset capitalization flag */
            } else {
                putchar(current_char + ASCII_OFFSET); /* Convert to lowercase */
            }
        } else if (!is_digit(current_char)) {
            /* Print non-alphanumeric characters as-is */
            putchar(current_char);
        }
        /* Numbers are skipped implicitly */
    }

    return 0;
}
