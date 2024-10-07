/* Example 11:This program is to test the word count program. What kinds of input are most likely to uncover bugs if there are any?
 
Name         : Ayesha Shaik
Created Date : 24-06-2024
Modified date: 24-06-2024
*/

/* REQUIRED HEADER FILES */
#include <stdio.h>


/*
 * main: 
 * The main function serves as the entry point of the program. 
 * It reads input from the user until EOF (End of File) or newline is encountered 
 * and calculates the number of words, characters, and new lines. 
 * Finally, it prints the counts.
 */
int main()
{
    char ch;
    // Temporary variable for storing characters
        int word_count = 0;
         // Counts the number of words in the input
	int char_count = 0;
         // Counts the number of charcters in the input
        int character = 0;
	 // Stores the current character read from input
        int in_word = 0;
	// Flag to track if currently inside a word
	int new_line=0;
	// Counts the number of new lines in the input

       printf("enter input to count the no.of newlines,words and charcaters\n");
    /*
     * The while loop reads characters one by one from the input until EOF is encountered.
     * This loop is responsible for counting characters, words, and new lines.
     */
        while ((character = getchar()) != EOF) 
	{
            char_count++;
	    // Increment character count for each character read

	      /* Count new lines*/
	    if(character=='\n')
	    {
		    // Increment new line count for each newline character
		    new_line++;
	    }


        /*
         * If the character is a space, tab, or newline, and we are currently inside a word, 
         * it signifies the end of a word. We then increment the word count.
         */
            if (character == ' ' || character == '\t' || character == '\n') 
	    {
                if (in_word)
	       	{
			 // Increment word count if inside a word
                    word_count++;
		    // Reset flag to indicate that we are no longer in a word
                    in_word = 0;
                }
            } 
	    else
	    {
                in_word = 1;
		 // Set flag to indicate that we are inside a word
            }
        }

         /*
     * If the last character is part of a word, it might not be followed by 
     * a space, tab, or newline, so we count it here.
     */
        if (in_word) 
	{
            word_count++;
	    // Increment word count for the last word
        }

	  /*
     * The final counts are printed here:
     * new_line - Number of new lines
     * word_count - Number of words
     * char_count - Number of characters
     */

        printf("%d %d %d\n",new_line, word_count , char_count);
}

