/** 
 * Exercise 1:
 * This program modifies the `getint` function to correctly handle 
 * '+' or '-' not followed by a digit as invalid input and pushes 
 * such a character back to the input buffer.
 * 
 * Author: Sk. Ayesha
 * Created: 17 July, 2024
 * Modified: 18 August, 2024        
 */

#include <stdio.h>    // Standard I/O functions like printf, getchar
#include <ctype.h>    // Character handling functions like isdigit, isspace

#define BUFFSIZE 100  // Size of the buffer used for ungetch function

// Buffer for ungetch
static char Cbuf[BUFFSIZE];  // Buffer to hold pushed-back characters
static int Ibufp = 0;         // Current position in the buffer

/** FUNCTION PROTOTYPES */
int getch(void);           // Function to get a character from input or buffer
void ungetch(int Ic);      // Function to push a character back to the input buffer
int getint(int *pn);       // Function to read the next integer from input and store it in *pn

/** MAIN PROGRAM */
int main(void) {
    int Inumber;    // Variable to store the integer input

    // Function call which attempts to retrieve an integer
    int Iresult = getint(&Inumber);  // Result of getint() stored in Iresult

    // If the result is 0, it means the input was invalid
    if (Iresult == 0) {
        printf("Invalid entry\n");  // Inform the user about invalid input
    } else { // If the result is not 0, it means the input was valid
        printf("%d\n", Inumber);  // Output the valid integer
    }

    return 0;
}
/* End main() */

/**
 * getint: Get the next integer from input and store it in *pn.
 * 
 * Author: Sk. Ayesha
 * Created: 17 July, 2024
 * Modified: 18 August, 2024        
 * 
 * Variables:
 * - Ic: Holds the current character being processed
 * - Isign: Stores the sign of the number (positive or negative)
 * - *pn: Pointer to the location where the parsed integer will be stored.
 * 
 * Purpose of the pointer:
 * The pointer `*pn` allows the function to directly modify the value of the variable 
 * in the calling function. This way, the integer parsed from the input can be 
 * stored in the location `*pn` points to, enabling `main()` to access this value.
 * 
 * Returns 1 if a valid integer was found, 0 if the input is invalid.
 */
int getint(int *pn) {
    int Ic, Isign;

    // Skip white space
    while (isspace(Ic = getch())) {
        ;  // Continue to get the next character until a non-whitespace character is found
    }

    // If the input character is not a digit, EOF, '+', or '-', it is invalid
    if (!isdigit(Ic) && Ic != EOF && Ic != '+' && Ic != '-') {
        ungetch(Ic);  // Push the invalid character back to input buffer
        return 0;     // Return 0 indicating invalid input
    }

    // Determine the sign of the number
    Isign = (Ic == '-') ? -1 : 1;  // Set sign based on whether the character is '-' or '+'

    // If the character is '+' or '-', check if it's followed by a digit
    if (Ic == '+' || Ic == '-') {
        Ic = getch();
        // If the character following '+' or '-' is not a digit, input is invalid
        if (!isdigit(Ic)) {
            ungetch(Ic);  // Push the non-digit character back to input
            return 0;     // Return 0 indicating invalid input
        }
    }

    // If the input is valid, construct the number from the digits
    for (*pn = 0; isdigit(Ic); Ic = getch()) {
        *pn = 10 * *pn + (Ic - '0');  // Construct the integer from its digits
    }

    *pn *= Isign;  // Apply the sign to the number

    // If the current character is not EOF, push it back to the input buffer
    if (Ic != EOF) {
        ungetch(Ic);  // Push the last character back to the input buffer
    }

    return 1;  // Return 1 indicating valid input
}
/* end of getint() */

/** 
 * BUFFER MANAGEMENT
 * These functions manage a buffer for pushing characters back to input.
 */

/**
 * getch: Get a (possibly pushed-back) character.
 * 
 * Author: Sk. Ayesha
 * Created: 17 July, 2024
 * Modified: 18 August, 2024        
 * 
 * Returns the next character from the input buffer or reads it from stdin.
 */
int getch(void) {
    // Check if there are characters in the buffer; if so, return the last pushed-back character
    return (Ibufp > 0) ? Cbuf[--Ibufp] : getchar();  
}

/**
 * ungetch: Push a character back onto the input buffer.
 * 
 * Author: Sk. Ayesha
 * Created: 17 July, 2024
 * Modified: 18 August, 2024        
 * 
 * - Ic: The character to be pushed back into the input buffer
 */
void ungetch(int Ic) {
    // If the buffer is full, print an error message
    if (Ibufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");  // Indicate an error when too many characters are pushed back
    } else { // If there is space in the buffer, push the character
        Cbuf[Ibufp++] = Ic;  // Store the character in the buffer
    }
}
/* End of ungetch */

