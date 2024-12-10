#include <stdio.h>
#define CAPORDECAP 32
int main(void) {
    int current_char;
    int capitalized = 1;/* Tells the program whether to capitalize the next letter */
    printf("Please enter a text. Note that sentence ends in '.' character\n");
    while ((current_char = getchar()) != EOF) {
        if (current_char == '.') {
            /* We reached the end of a sentence */
            putchar(current_char);
            capitalized = 1; /* Flag indicating the later letter will be capitalized */
        } else if (current_char >= 'a' && current_char <= 'z' && capitalized == 1) {
            /* Capitalize lowercase at the beginning of a sentence */
            putchar(current_char - CAPORDECAP);
            capitalized = 0; /* Resetting the flag */
        } else if (current_char == '"') {
            /* Handle quoted text */
            putchar(current_char);
            while ((current_char = getchar()) != '"' && current_char != EOF ) {
                if (current_char >= 'a' && current_char <= 'z') {
                    putchar(current_char - CAPORDECAP); /* Capitalize inside quotes */
                } else if (current_char < '0' || current_char > '9'){
                    putchar(current_char);
                }
            }
            if (current_char == '"') {
                putchar(current_char); /* Print closing quote */
            }
        } else if (current_char >= 'A' && current_char <= 'Z') {
            /* Convert uppercase to lowercase unless it's the start of a sentence */
            if (capitalized == 1) {
                putchar(current_char); /* Keep uppercase */
                capitalized = 0;       /* Reset capitalization flag */
            } else {
                putchar(current_char + CAPORDECAP); /* Convert to lowercase */
            }
        } else if (current_char < '0' || current_char > '9') {
            /* Print non-alphanumeric characters as-is */
            putchar(current_char);
        }
        /* Numbers are skipped implicitly */
    }
    return 0;
}
