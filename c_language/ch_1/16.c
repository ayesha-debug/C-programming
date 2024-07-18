/*Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print 
the length of arbitrary long input lines, and as much as possible of the text.*/

/*
 * Name		:Sk.Ayesha
 * Date 	:4.07.2024
 *Modified Date :4.07.2024
 *
 */

/*HEADER FILES*/
#include <stdio.h>

int main()
{
	char ch;
	char big_line[100];
	char present_line[100];
	int big_line_length = 0,total_char = 0,line = 0,count=0;
	int i = 0,j = 0; 
	big_line[0] = '\0'; 
	while((ch = getchar()) != EOF)
	{
		if(((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		{
		 total_char++;
		}
		
		present_line[i++] = ch;
		count++;
		
		if(ch == '\n')
		{
			line++;
			present_line[i] = '\0';
			if(count > big_line_length)
			{
				big_line_length = count;
				for(j = 0;j <= i;j++)
				{
					big_line[j] = present_line[j];
				}
	                          	                
	         	}
			count = 0;
			i = 0;

		
		}
	
	
		
	}
       	printf("total_char = %d\n",total_char);
        printf("no.of lines = %d\n",line);
        printf("big_line = %s  big_line_length = %d\n",big_line,big_line_length-1);
  }



/*End of the program*/
