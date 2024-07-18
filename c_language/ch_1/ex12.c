//Exercise 1-12. Write a program that prints its input one word per line

/*
 * Name         :Sk.Ayesha
 * Created      :22-06-2024
 * Modified Date:22-06-2024
 */

/*Header Files*/
#include<stdio.h>

/*Main function starts Here*/
int main()
{
	int input;
	// Variable to store each character read from input
	printf("enter the words\n");

	// Loop to read each character until EOF
	while((input = getchar()) != EOF)
	{
		if((input == ' ') || (input == '\t')||(input == '\n'))
			printf("\n");
		 // Print newline for spaces, tabs, or newlines
		else
			putchar(input);
		 // Print the character if it's not a space, tab, or newline
	}
}
/*End of the main function*/
