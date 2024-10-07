/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
* Author:Ayesha Shaik
* Created: 28 June, 2024
* Modified:28 June, 2024
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define MAX 50
// Maximum size of the input string

/** FUNCTION PROTOTYPES */
void horizontal_hist(char[]);
 // Function to print the horizontal histogram
void vertical_hist(char[]);
 // Function to print the vertical histogram
 
/** MAIN PROGRAM */
/**
 * main: 
 * The main function accepts characters from the user until EOF is encountered. 
 * It stores the characters in a string and then calls the functions to print 
 * both horizontal and vertical histograms of the word lengths.
 */
int main()
{
   char str[MAX];
   // Array to store the input characters
   char character;
   // Variable to store each character read from input
   int count = 0;
   
   // Reading characters from user input until EOF is reached
   while((character=getchar())!=EOF)
   {
	 // Store character in the array and increment count
	str[count++]=character;

   }

    //NULL Terminate the string
    str[count]='\0';

    //calling horizontal histogam function
    printf("horizontal histogram\n");
    horizontal_hist(str);
    
    //calling vertical histogram function
    printf("vertical histogram\n");
    vertical_hist(str);
}
/*End of main()*/

/**
 * horizontal_hist:
 * This function takes the input string and prints a horizontal histogram
 * representing the lengths of the words in the input.
 * Each word is represented by a series of '*' characters.
 */
void horizontal_hist(char str[]) 
{
     // Index to iterate through the string
    int start;
     // Counter to track the length of the current word
    int count = 0;

    // Loop through the input string
    for (start = 0; str[start] != '\0'; start++) 
    {
	    // Check if the character is a space, tab, or newline (word boundary)
        if (str[start] == '\n' || str[start] == '\t' || str[start] == ' ') 
	{
            if (count > 0) 
	    {
                printf("\n");
                // Reset word length counter
	    	count = 0;
            }
        } 
	else
       	{
		// Print a '*' for each character in the word
            printf("*");
	     // Increment word length counter
            count++;
        }
    }
     // Print a newline after the last word
    if (count > 0) {
        printf("\n");
    }
} 
/* End of horizontal_hist() */

/**
 * vertical_hist: 
 * This function takes the input string and prints a vertical histogram 
 * representing the lengths of the words in the input. 
 * Each word is represented by a vertical column of '*' characters.
 */
void vertical_hist(char str[]) 
{
	 // Index to iterate through the string
    int start;
     // Counter to track the length of the current word
    int count = 0;
     // Array to store the lengths of the words
    int word_lengths[100]; 
    // Counter to track the number of words
    int word_count = 0;
    
     // Loop through the input string to calculate word lengths
    for (start = 0; str[start] != '\0'; start++) 
    {
	      // Check if the character is a space, tab, or newline (word boundary)
        if (str[start] == '\n' || str[start] == '\t' || str[start] == ' ') 
	{
            if (count > 0) 
	    {
		  // Store word length in array
                word_lengths[word_count] = count;
                 // Increment word count
                word_count++;
		// Reset word length counter
                count = 0;
            }
        } 
	else
       	{
	    // Increment word length counter
            count++;
        }
    }
    
     // Store the length of the last word if there is one
    if (count > 0) 
    {
        word_lengths[word_count] = count;
        word_count++;
    }

    
    // Find the maximum word length to determine the height of the histogram
    int j, max_length = 0;
    for (j = 0; j < word_count; j++) 
    {
        if (word_lengths[j] > max_length) 
	{
		// Update maximum word length
            max_length = word_lengths[j];
        }
    }

    // Print the vertical histogram
    int k;
    for (j = max_length; j > 0; j--) 
    {
	     // Loop from max_length down to 1
        for (k = 0; k < word_count; k++) 
	{
		// Loop through each word
            if (word_lengths[k] >= j) 
	    {
		     // Print '*' if the word length is >= current height
                printf(" * ");
            }
	    else
	    {
		    // Print space otherwise
                printf("   ");
            }
        }
	// Print a newline after each row of the histogram
    
        printf("\n");
    }
}
/*End of vertcal_hist()*/

