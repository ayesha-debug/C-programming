/*
 * This program writes an alternative version of squeeze(s1, s2) that deletes each character in
 * s1 that matches any character in the string s2.
 * Author: Sk. Ayesha
 * Created: 3 July, 2024
 * Modified: 3 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define LIMIT 100

/** FUNCTION PROTOTYPES */
void squeeze(char str[], char sub_str[]);

/** MAIN PROGRAM */
/**
 * main: Reads input strings and calls the squeeze function to delete 
 * common characters from the first string.
 */
int main() {
    char str[LIMIT];
    char sub_str[LIMIT];
    char ch;

    do {
        // Prompt user for input strings
        printf("Enter the string s1:\n");
        scanf("%[^\n]", str);

        printf("Enter the string s2:\n");
        scanf(" %[^\n]", sub_str);

        // Call squeeze function to remove common characters from str
        squeeze(str, sub_str);

        // Print the modified string
        printf("Resulting string: %s\n", str);

        // Ask user if they want to repeat the operation
        printf("Do you want to repeat again? (y/n): ");
        scanf(" %c", &ch);

        // Clear the input buffer
        while (getchar() != '\n');

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
/* End main() */

/**
 * squeeze: Removes each character from 'str' that matches any character in 'sub_str'.
 * 
 * Parameters:
 *   str - The original string from which characters will be removed.
 *   sub_str - The string containing characters to be removed from 'str'.
 */
void squeeze(char str[], char sub_str[]) {
    int start, j, k = 0;
    int found;

    // Iterate through each character in str
    for (start = 0; str[start] != '\0'; start++) 
    {
        found = 0;

        // Check if current character in str is found in sub_str
        for (j = 0; sub_str[j] != '\0'; j++) 
	{
            if (tolower(str[start]) == tolower(sub_str[j])) 
	    {
                found = 1;
                break;
            }
        }

        // If the character is not found in sub_str, keep it in str
        if (found == 0) 
	{
            str[k++] = str[start];
        }
    }

    // Null-terminate the modified string
    str[k] = '\0';
}
/* End squeeze() */

