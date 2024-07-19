//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
/*
 * Name         :Sk.Ayesha
 * Created      :22-06-2024
 * Modified Date:22-06-2024
 */

/*Required Header Files*/
#include <stdio.h>

/*Required header files*/
#define TOTAL_CHAR 256  
// Total number of possible characters (ASCII range)

int main(void) 
{
    int input; 
    // Variable to store the current character from input
    int char_frequencies[TOTAL_CHAR] = {0};  
    // Array to store frequencies of characters

    /* Read input and count character frequencies*/
    while ((input = getchar()) != EOF) 
    {
        char_frequencies[input]++;
    }

    /* Print the histogram*/
    printf("\nCharacter Frequency Histogram:\n");
    for (int start = 0; start < TOTAL_CHAR; start++)
    {
        if (char_frequencies[start] > 0) 
	{
            if (start >= 32 && start <= 126)
	    { 
	        // Print printable characters
                printf("%c - ascii value is %d : ",start, start);
            } 
	    else 
	    {  
		// Print non-printable characters as their ASCII values
                printf("%d: ", start);
            }
            for (int ends = 0; ends < char_frequencies[start]; ends++) 
	    {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}

/*End of the main function*/ 
