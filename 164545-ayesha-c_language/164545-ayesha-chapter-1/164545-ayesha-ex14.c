//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
/*
 * Name         :Sk.Ayesha
 * Created      :22-06-2024
 * Modified Date:22-06-2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define MAX 50
 // Maximum size of the input string

/** MAIN PROGRAM */
/**
 * main:
 * This function reads a string input from the user until EOF is encountered and prints
 * a histogram of the frequencies of different characters in the input.
 */
int main()
{
	// Array to store the input string
	char str[MAX];
	// Variable to store each character read from input
	char ch;
	// Counter to track the number of characters in the input string
	int i=0;
	 // Loop indices for iterating through the string
	int start,end;
	// 'k' for printing stars, 'count' for character frequency
	int k,count=0;

	printf("enter a string to print the frequencies of different characters\n");

	// Reading characters from user input until EOF is reached
	while((ch=getchar())!=EOF)
	// Store the character in the array and increment counter
	str[i++]=ch;
	 // NULL-terminate the string to mark the end of the input
	str[i]='\0';

			printf("\n");

	// Loop through the input string to find and print character frequencies
	for(start=0;str[start];start++)
	{
		 // Inner loop to check if the current character has already been counted
		for(end=0;end<start;end++)  
		{
			if(str[start]==str[end])
				// If character is already counted, exit inner loop
				break;
		}
		
		 // If character hasn't been counted yet, proceed to count its frequency
		if(end==start)  
		{  
			 // Initialize count for the current character

            // Loop to count occurrences of the current character
			for(end=start+1,count=1;str[end];end++)
				if(str[start] == str[end])
					count++;
			// Print the character (handling spaces, tabs, and newlines)     
			if (str[start] == ' ') 
			{
                           printf("\\s ");
                        } 
			else if (str[start] == '\t') 
			{
                            printf("\\t ");
                        } 
			else if (str[start] == '\n') 
			{
                            printf("\\n ");
                        } 
		      	else 
			{
                              printf("%c ", str[start]);
	                }
			
			 // Print the histogram (number of '*' corresponding to character frequency)
			for( k=0;k<count;k++)
				printf("*");
			// Move to the next line after printing histogram
			printf("\n");
		}
	}
}
/* End main() */


