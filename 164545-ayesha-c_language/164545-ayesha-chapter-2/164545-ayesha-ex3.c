/*
 * This program is to write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into 
 * its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.  
* Author: Sk.Ayesha
* Created: 3 July, 2024
* Modified:3 July, 2024
*/
/** REQUIRED HEADER FILES */

/** REQUIRED HEADER FILES **/
#include <stdio.h>

/** MACRO DEFINITIONS **/
#define RANGE 100

/** FUNCTION PROTOTYPES **/
int my_htoi(const char str[]);

/** MAIN PROGRAM **/
/**
 * Brief: Main function to get hexadecimal input from the user and convert it to an integer.
 * Return: Returns 0 if the program completes successfully.
 */
int main(void) {
    int iOutput;
    char sInput[RANGE], cContinue;

    /* do while: Ask the user if they want to repeat the process */
    do {
        printf("Enter a hexadecimal number (e.g., 0x1A3F): ");
        scanf(" %[^\n]", sInput);

        /* FUNCTION CALL */
        iOutput = my_htoi(sInput);

        /* Return the integer value */
        if (iOutput == -1) {
            printf("Error: Enter a valid hexadecimal number.\n");
        } else {
            printf("Decimal equivalent = %d\n", iOutput);
        }

        printf("Do you want to give input again? (y/n): ");
        scanf(" %c", &cContinue);
    } while (cContinue == 'y' || cContinue == 'Y');

    return 0;
}

/** FUNCTION DEFINITIONS **/

/**
 * Brief: Converts a string representing a hexadecimal value into an integer.
 * Param: const char str[] - Input string representing a hexadecimal value.
 * Return: Returns the equivalent integer value, or -1 if the input is not a valid hexadecimal.
 */
int my_htoi(const char str[]) {
    int iIndex = 0;
    int iSum = 0;

    /* Check for optional "0x" or "0X" prefix */
    if ((str[0] == '0') && ((str[1] == 'x') || (str[1] == 'X'))) {
        iIndex = 2;
    } else {
        return -1;  // Invalid hexadecimal format
    }

    /* Convert hexadecimal digits to integer value */
    for (; str[iIndex] != '\0'; iIndex++) {
        int iValue;

        if (str[iIndex] >= '0' && str[iIndex] <= '9') {
            iValue = str[iIndex] - '0';
        } else if (str[iIndex] >= 'a' && str[iIndex] <= 'f') {
            iValue = str[iIndex] - 'a' + 10;
        } else if (str[iIndex] >= 'A' && str[iIndex] <= 'F') {
            iValue = str[iIndex] - 'A' + 10;
        } else {
            return -1;  // Invalid character found
        }

        iSum = iSum * 16 + iValue;
    }

    return iSum;
}

/** End of my_htoi **/

