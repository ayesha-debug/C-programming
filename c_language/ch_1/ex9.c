//Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

/*
 * Author       :Sk.Ayesha
 * Created      :22-06-2024
 * Modified     :22-06-2024
 */

/* Required Header Files */
#include <stdio.h>

/* Main Function Starts Here */
int main()
{
	char input[20];
	 // Buffer to store input string

	int starts,ends;
	printf("enter the string\n");
	scanf("%[^\n]",input);

	 // Loop to replace multiple spaces with a single space
	for(starts = 0;input[starts];starts++)
	{
		// Skip over consecutive spaces
		if((input[starts] == ' ') && (input[starts+1] == ' '))
		{
			  // Shift characters left to overwrite consecutive spaces
			for(ends = starts;input[ends];ends++)
           		input[ends]= input[ends+1];
			starts--;
			
		}
	}
	
	// Output the modified string
	printf("After Modification of the string\n%s\n",input);
}
/*End of the Main Function*/


