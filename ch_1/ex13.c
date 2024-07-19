/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
/*
 * Name         :Sk.Ayesha
 * Created      :22-06-2024
 * Modified Date:22-06-2024
 */

/*Required Header Files*/
#include <stdio.h>
#include <ctype.h>

/* Maximum word length we consider for the histogram*/
#define MAX_WORD_LENGTH 20  

/*Main function starts here*/
int main(void) 
{
    int input;  
    // Variable to store the current character from input
    int no_of_chars = 0;  
    // Variable to count the number of characters in the current word
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};  
    // Array to store the counts of word lengths

    /* Read input and count word lengths*/
    while ((input = getchar()) != EOF) 
    {
	  /* Check if the character is an alphabet letter*/
        if (isalpha(input)) 
	{
		no_of_chars++;
	  	  // Increment character count for the current word
        } 
	
      	/* If a word boundary is encountered and there was a word*/
	else if (no_of_chars > 0) 
	{
	    /* If the word length is within the limit*/
		if (no_of_chars <= MAX_WORD_LENGTH) 
		{
			word_lengths[no_of_chars]++;  
		// Increment the count for this word length
                } 
	    
	    /* If the word length exceeds the limit*/
	       else
	    {
                word_lengths[MAX_WORD_LENGTH]++;  
		// Increment the count for the maximum length
            }
            no_of_chars = 0;
	    // Reset the character count for the next word
        }
    }

    /* If the last character is part of a word, include its length*/
    if (no_of_chars > 0)
    {
        if (no_of_chars <= MAX_WORD_LENGTH) 
	{
            word_lengths[no_of_chars]++;
        }
       	else 
	{
            word_lengths[MAX_WORD_LENGTH]++;
        }
    }

    /* Print the histogram*/
    printf("\nWord Length Histogram:\n");
    
    /* Iterate over possible word lengths*/
    for (int start = 1; start <= MAX_WORD_LENGTH; start++) 
    {  
        printf("  length is %2d: ",start); 
       	// Print the word length
        
       	/* Print asterisks for the count of each word length*/
	for (int end = 0; end < word_lengths[start]; end++)
	{
		printf("*");
        }
        printf("\n");
    }

    return 0;
}
/*End of the main program*/
