/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.*/
/* 
 * Author         : Sk.Ayesha
 * Created Date   : 23:07:2024
 * Modified Date  : 23:07:2024
 */

/* Header Files */
#include <stdio.h>

/*Required Macros*/
#define MAXLINE 1000  
// Maximum input line size
#define LIMIT 8       
// Minimum length to print the line

/* Function Prototypes */
int get_line(char line[], int max_length);

/* Main Function */
int main(void) 
{
    int line_length;        
    // Length of the current line
    char line[MAXLINE];    
    // Buffer to store the current line

    /* Read lines until end of input*/
    while ((line_length = get_line(line, MAXLINE)) > 0) 
    {
        /* Print the line if its length exceeds LIMIT*/
        if (line_length > LIMIT) 
	{
            printf("The line exceeds 8 characters --> %s", line);
        }
    }

    return 0;
}

/* get_line: Read a line into 'line[]', return length of the line */
int get_line(char line[], int max_length) 
{
    int character;    
    // Current character read from input
    int index;   
    // Index to store characters in the line buffer

    /* Read characters into the line buffer*/
    for (index = 0; index < max_length - 1 && (character = getchar()) != EOF && character != '\n'; ++index) 
    {
        line[index] = character;  
	// Store each character in the line buffer
    }

    /* Add newline character if it was encountered*/
    if (character == '\n') 
    {
        line[index] = character;
        ++index;
    }

    line[index] = '\0';  
    // Null-terminate the string

    return index;       
    // Return the length of the line
}

