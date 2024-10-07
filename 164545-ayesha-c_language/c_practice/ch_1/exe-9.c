/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or 
more blanks by a single blank.*/
#include<stdio.h>
int main()
{
	char input;
	int start,blank = 0;
	while((input = getchar()) != EOF)
	{
		if(input == ' ')
		{
			if(!blank)
			{
				putchar(input);
			blank = 1;
			}
		}	
		
		else
		{
                   putchar(input); 
		   blank = 0;
		}
		
	}

}
