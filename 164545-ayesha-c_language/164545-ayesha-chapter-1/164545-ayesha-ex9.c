/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or 
more blanks by a single blank.
input	       : ***\thello****world\t\n
Expected output:*hello*world*
*/

/*
 * Author	:Sk.Ayesha
 * Created	:23-06-2024
 * Modified	:23-06-2024
 */

/*Required Header Files*/
#include<stdio.h>
#include <stdbool.h> 
// Provides the bool type and true/false macros

/**
 * @brief Main function to process input and replace multiple whitespace characters
 *        with a single space.
 *
 * @return int Returns 0 upon successful execution.
 */

/*main function starts here*/
int main()
{
    int character;
    bool in_blank_sequence = false;
    // Tracks whether the current character is part of a blank sequence

    printf("Enter the input characters to replace multiple whitespace characters with a single space\n");
    // Read characters from input until end-of-file (EOF) is reached
    while ((character = getchar()) != EOF) 
    {
        // Check if the character is a space, tab, or newline
        if (character == ' ' || character == '\t' || character == '\n') {
            if (!in_blank_sequence) 
	    {
                putchar(' ');
	      	// Print a single space for a sequence of whitespace
                in_blank_sequence = true;
            }
        } 
	else 
	{
            putchar(character);  
	    // Print the non-whitespace character
            in_blank_sequence = false;
        }
    }

    return 0;  // Return 0 to indicate successful execution
}

