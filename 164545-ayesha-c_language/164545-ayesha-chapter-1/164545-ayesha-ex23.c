/* Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest
* Author: Sk.Ayesha
* Created: 4 July, 2024
* Modified:9 July, 2024
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define MAX_SIZE 500  // Maximum size for input buffer

/** FUNCTION PROTOTYPES */
void skip_comments(char *input_str);

/** MAIN PROGRAM */
/**
 * main: Reads input from a file and removes all comments in it.
 */
int main(void) 
{
    char input_str[MAX_SIZE];
    int i = 0;
    char ch;

    // Read input from user/file until EOF
    while ((ch = getchar()) != EOF && i < MAX_SIZE - 1) 
    {
        input_str[i++] = ch;
    }
    input_str[i] = '\0';  // Null-terminate the string

    // Remove comments from the input string
    skip_comments(input_str);

    // Print the modified string without comments
    printf("%s\n", input_str);

    return 0;
}

/** FUNCTION DEFINITIONS */
/**
 * skip_comments: Removes all comments from the given input string.
 */
void skip_comments(char *input_str) 
{
    int read_idx = 0;  // Index to read characters from the input
    int write_idx = 0; // Index to write characters into the output

    while (input_str[read_idx] != '\0') 
    {
        if (input_str[read_idx] == '/' && input_str[read_idx + 1] == '/') {
            // Skip line comments
            read_idx += 2;  // Skip the "//"
            while (input_str[read_idx] != '\n' && input_str[read_idx] != '\0') 
	    {
                read_idx++;
            }
        } 
	else if (input_str[read_idx] == '/' && input_str[read_idx + 1] == '*') 
	{
            // Skip block comments
            read_idx += 2;  // Skip the "/*"
            while (!(input_str[read_idx] == '*' && input_str[read_idx + 1] == '/') && input_str[read_idx] != '\0') 
	    {
                read_idx++;
            }
            if (input_str[read_idx] != '\0') 
	    {
                read_idx += 2;  // Move past the closing "*/"
            }
        } 
	else
       	{
            // Copy non-comment characters to the output
            input_str[write_idx++] = input_str[read_idx++];
        }
    }
    input_str[write_idx] = '\0';  // Null-terminate the modified string
}
/* End main() */


