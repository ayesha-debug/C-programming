/*Example 12:This program prints its input one word per line. 

Name         :Ayesha Shaik
Created Date :24-06-2024
Modified date:24-06-2024
 */

/*REQUIRED HEADER FILES*/
#include<stdio.h>
  // Required for standard input/output functions


/*
 * main: 
 * The main function reads input characters from the user until EOF (End of File) is encountered. 
 * It stores the characters in a string and then processes the string to print each word on a new line.
 */
int main()

{
	// Variable to store the current character input by the user
	int chars;
	 // Index to track the position in the string array
	int index=0;
	// Array to store the input characters, limited to 100 characters
	char str[100];
	printf("enter characters to print input into one word per line:\n");

	/*
     * The while loop reads characters from user input until EOF is reached.
     * Each character is stored in the 'str' array, and the index is incremented.
     */
	while((chars=getchar())!=EOF)
	{
		// Store character and increment index
		str[index++]=chars;

	}
	 // Null-terminate the string to mark the end of input
	str[index]='\0';
    
    // Loop counter for iterating through the string
    int i;
    int space_detected = 0; 
    // Flag to detect space or tab sequence

    /*
     * The for loop processes each character in the string 'str'.
     * It checks for spaces or tabs to determine word boundaries.
     * If a space or tab is detected, a newline is printed to move to the next line.
     * Otherwise, the character is printed, and the flag is reset.
     */
    for (i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == ' ' || str[i] == '\t'||str[i]=='\n') 
	{
		  // Check for spaces or tabs
            if (!space_detected)
	    {
		     // Print newline to start a new word on a new line
                putchar('\n');
                space_detected = 1; 
		// Set flag when a space or tab is detected
            }
        } 
	else
       	{
		// Print the character if it's not a space or tab
            putchar(str[i]);
            space_detected = 0; 
	    // Reset flag when a non-space character is detected
        }
    }
     // Exit the program successfully

    return 0;
}


/*End of main()*/

