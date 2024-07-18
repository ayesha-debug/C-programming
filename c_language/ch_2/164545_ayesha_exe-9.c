
/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions. */
/*
 * Author: Sk.Ayesha
 * Created: 27-06-2024
 * Modified:27-06-2024
 * */
// REQUIRED HEADER FILES
#include <stdio.h>

// Function prototype
int rightrotate(unsigned int x, int p);
void printbinary(int x, int size);

//MAIN FUNCTION
int main() {
    int x;
    int p;

    // Input values for x and p
    scanf("%d %d", &x, &p);

    // Check if x is non-negative
    if (x < 0) {
        printf("Number must be non-negative.\n");
        return 0;
    }

    // Print binary representation of x before rotation
    printf("Original binary representation:\n");
    printbinary(x, sizeof(x));
    return 0;
}

// Function to perform right rotation on x by p bits
int rightrotate(unsigned int x, int p) {
        int i;
        for (i = 0; i < p; i++) {
                // Check if the rightmost bit is set
                if (x & 0x1) {
                        // If set, right shift x by 1 and set the leftmost bit
                        x = x >> 1;
                        x = x | (0x1 << (sizeof(x) * 8 - 1));
                } else {
                        // If not set, right shift x by 1 and clear the leftmost bit
                        x = x >> 1;
                        x = x & ~(0x1 << (sizeof(x) * 8 - 1));
                }
        }
        return x;
}
