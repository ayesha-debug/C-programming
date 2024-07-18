//Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
/*
 * Name 	:Sk.Ayesha
 * Created	:22-06-2024
 * Modified Date:22-06-2024
 */

/*Header Files*/
#include<stdio.h>

/*Main function starts Here*/
int main()
{
	int input;
	int word_count=0;
	// Initialize word count to zero
	printf("enter the char\n");

	// Loop to count words based on spaces, tabs, and newlines
	while((input = getchar()) != EOF)
	{
		if((input == ' ') || (input == '\t') || (input == '\n'))
			word_count++;
		// Increment word count for each space, tab, or newline
	}
	printf("word_count is %d\n",word_count);
	// Output the total word count
}

/*END OF THE MAIN FUNCTION*/
