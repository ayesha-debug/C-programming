/*Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print 
the length of arbitrary long input lines, and as much as possible of the text.*/

/*
*Author         :Ayesha
*Created Date   :23:07:2024
*Modified Data  :23:07:2024
*/

/* Header Files */
#include <stdio.h>

/*Require Mcros*/
#define MAXLINE 1000  
// Maximum input line size

/* Function Prototypes */
int get_line(char current_line[], int max_length);
void copy_line(char from[], char to[]);

/* Main Function starts here */
int main(void) 
{
    int current_length;  
    // Current line length
    int max_length = 0;  
    // Maximum length seen so far
    char current_line[MAXLINE]; 
    // Current input line
    char longest_line[MAXLINE];  
    // Longest line saved here

    /* Read lines until end of input */
    while ((current_length = get_line(current_line, MAXLINE)) > 0) 
    {
        /* Check if the current line is longer than the longest line seen so far*/
        if (current_length > max_length) 
	{
            max_length = current_length;  
	    // Update the maximum length
            copy_line(current_line, longest_line); 
	    // Copy the current line to longest_line
        }
        /*Print the length of the current line*/
        printf("Line length: %d\n", current_length);
    }

    /* If there was at least one line, print the longest line*/
    if (max_length > 0) 
    {
        printf("Longest line is %s with length \n", longest_line);
    }
    return 0;
}
/*main function ends here*/

/* get_line: read a line into current_line[], return length */
int get_line(char current_line[], int max_length) 
{
    int character, start;

    /* Read characters into the line buffer */
    for (start = 0; start < max_length - 1 && (character = getchar()) != EOF && character != '\n'; ++start)
    {
        current_line[start] = character; 
       	// Store each character in the current_line array
    }
    if (character == '\n') 
    {
        current_line[start] = character;
      	// Include the newline character in the line
        ++start;
    }

    current_line[start] = '\0'; 
    // Null-terminate the string

    /* Continue reading the rest of the line if it's longer than max_length*/
    while (character != EOF && character != '\n') 
    {
        ++start;  
	// Increment the length counter
        character = getchar();  
	// Read the next character
    }
    return start; 
    // Return the length of the line
}

/* copy_line: copy 'from' into 'to'; assume to is big enough */
void copy_line(char from[], char to[]) 
{
    int start = 0;

    /* Copy characters from 'from' array to 'to' array*/
    while ((to[start] = from[start]) != '\0') 
    {
        ++start;
    }
}
