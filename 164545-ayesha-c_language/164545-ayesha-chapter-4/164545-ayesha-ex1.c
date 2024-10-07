/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none. */
/*
 * Author: Sk.Ayesha
 * Created: 23-07- 2024
 * Modified:23-07- 2024
 * */

/*Required Header Files*/
#include<stdio.h>
#include "error_handling.h"
/*Required Macros*/
#define max 100

/* Function Declarations */
void get_input(char *Main_str,int Max);
int strindex(char *Main_str,char *Sub_str);

/*Main function starts here*/
int main()
{
	char main_str[max];
        /* Array to store the main string */
	char sub_str[max];
	/* Array to store the substring */
	int result;
	 /* Variable to store the result of strindex function */

	 /* Prompt and get the main string input from the user */
	printf("Enter the main string  %s\n",main_str);
	get_input(main_str,max);

	 /* Prompt and get the sub string input from the user */
	printf("Enter the sub string  %s\n",sub_str);
	get_input(sub_str,max);
	
	/* Get the rightmost occurrence of the substring in the main string */
	result = strindex(main_str,sub_str);

	/* Check and print if the substring is present or not */
	if(result == -1)
	{
		printf("sub string is not present\n");
	}
	else
	{
		printf("sub string is present at %d index\n",result);
	}
	return 0;

}

/*
 * Function: strindex
 * ------------------
 * Returns the position of the rightmost occurrence of Sub_str in Main_str, or -1 if there is none.
 *
 * Main_str: The main string to be searched
 * Sub_str: The substring to search for
 ** returns: The index of the rightmost occurrence of Sub_str in Main_str, or -1 if not found
 */
int strindex(char Main_str[],char Sub_str[])
{
	int outer,inner,in;
         /* Variable to store the index of the last occurrence of the substring */
	int last_occurance = -1;
	
	 /* Loop through each character of the main string */
	for(outer = 0;Main_str[outer] != '\0';outer++)
	{
		 /* Nested loop to compare the substring with the main string starting from the current position */
		for(inner = outer,in = 0;Sub_str[in] != '\0' && Sub_str[in] == Main_str[inner];in++,inner++);
		 /* If the end of the substring is reached, update the last occurrence */
		if(Sub_str[in] == '\0')
		{
			last_occurance = outer;
		}
	}

	/* Return the index of the last occurrence, or -1 if not found */
	return last_occurance;
}

/*
 * Function: get_input
 * -------------------
 * Gets input from the user and stores it in Main_str.
 *
 * Main_str: The string to store the user input
 * Max: The maximum size of the string
 */

void get_input(char Main_str[],int Max)
{
	char input;
	int upper,index = 0;

	 /* Loop to get characters from the user until newline, EOF, or max size is reached */
	for(upper = Max;upper >= 0 && ((input = getchar()) != EOF && input != '\n');upper--)
	{
		Main_str[index++] = input;
	}
	if(index>max-1){
		handle_error(ERROR_OUT_OF_RANGE);
	
	}
	/* Null-terminate the string */
	Main_str[index++] = '\0';
}

