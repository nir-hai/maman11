#include <stdio.h>

/* Function to print binary representation of a number */
int decToBinary(unsigned long n) {
    /* size is calculated based on the total bits of n */
    for (int i =sizeof(n)*8-1; i >= 0; i--) {
        printf("%lu", (n>>i) & 1); /* right shifts n by i position and check the lsb */
    }
    printf("\n");
}

int main() {
    unsigned long x, y;

    /* Input the two numbers */
    printf("Enter the first number (x): ");
    scanf("%lu", &x);
    decToBinary(x);

    printf("Enter the second number (y): ");
    scanf("%lu", &y);
    decToBinary(y);

    /* Turn on the 13th bit of x (0-based indexing)*/
    x= (x | (1UL << (12)));

    // Check if the 7th bit of y is ON
    unsigned long seventh_bit = 1UL << 6; // 7th bit is index 6
    int is_7th_bit_on = (y & seventh_bit) != 0;

    printf("Updated x in binary: ");
    decToBinary(x);

    printf("Original y in binary: ");
    decToBinary(y);

    printf("Is the 7th bit of y ON? %s\n", is_7th_bit_on ? "YES" : "NO");

    return 0;
}
