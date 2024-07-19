/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters*/

/*
 * Name		:sk.Ayesha
 * Date		:4.07.2024
 * Modified Date:4.07.2024
 *
 */

/*HEADER FILE*/
#include<stdio.h>

/*MACROS*/
#define limit 80

int main()
{
	char ch;
	int total_char = 0,count = 0,line = 0,big_line_length = 0,i = 0,j = 0;
 	char present_line[100];
	char big_line[100];
	big_line[0] = '\0';

	while((ch = getchar()) != EOF)
	{
		if(((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		{	
		   total_char++;
		}
	
		present_line[i++] = ch;
		count++;
		
	        
		if (ch == '\n')
	        {  
			line++;
			present_line[i] = '\0';
		       
			if(count > big_line_length)
		        {
                           big_line_length = count;
			
			   for(j = 0;j <= i ;j++)
			    {
				 big_line[j] = present_line[j];

		            }
		       
			}
		if(count > limit)
		{
			printf("line with ,more than 80 characters :%s",present_line);
		}	
		count = 0;
		i = 0;
		}
	}
	printf("total_char is: %d\n",total_char);
	printf("big line is:%s  %d\n",big_line,big_line_length-1);
	printf("total_lines is: %d\n",line);

}
