/*count characters in input */
/*#include<stdio.h>
int main()
{
	char ch;
	int char_count = 0;
	while(ch = getchar() != EOF)
	   char_count++;
        printf("\n");	
	printf("character count is %d\n",char_count);
}*/



/*counting lines of the input stream*/
/*
#include<stdio.h>
int main()
{
	char input;
	int line_count = 0,start ;
	for(start = 0;(input = getchar()) != EOF;start++)
	{
		if(input == '\n')
		{
			line_count++;
		}
	}
	printf("line_count is %d\n",line_count);
}
*/

/*Exercise 1-8. Write a program to count blanks, tabs, and newlines.*/
#include<stdio.h>
int main()
{
	char input;
	int blank = 0,tab = 0,newline = 0;
	while((input = getchar()) != EOF)
	{
		if(input == '\n')
			newline++;
		else if(input == '\t')
			tab++;
		else if(input == ' ')
			blank++;
	}
	printf("\nnewline = %d\n tab = %d\n blank = %d\n",newline,tab,blank);
}
