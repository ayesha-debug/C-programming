/*
 * This program is to Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. 
 * Author: Sk.Ayesha
 * Created: 4 July, 2024
 * Modified:9 July, 2024
 */

/** REQUIRED HEADER FILES */

#include <stdio.h>  // Required for input/output functions

/** MACRO DEFINITIONS **/
#define COLUMN 10    // Number of characters per folded line

/** MAIN PROGRAM **/
/**
 *  Main function that accepts characters and folds long input lines into shorter lines of fixed width.
 */
int main(void)
{
    char cCharacter;          // Variable to store input characters
    int iIndex = 0;           // Index for storing characters in buffer
    char sLine[500];          // Buffer to store the input line

    // Read input from the user until EOF is encountered
    while ((cCharacter = getchar()) != EOF)
    {
        sLine[iIndex++] = cCharacter;
    }
    // Null-terminate the input line string
    sLine[iIndex] = '\0';

    // Process and fold the input line by the specified column width
    for (int iStart = 0; iStart < iIndex; iStart += COLUMN) 
    {
        // Print characters from the current position to the end of the current column width
        for (int iPos = iStart; iPos < iStart + COLUMN && iPos < iIndex; iPos++) 
	{
            printf("%c",sLine[iPos]);
        }
        printf("\n");  // Newline after each line of specified column width
    }

    return 0;  // Indicate successful program execution
}
/* End main() */

