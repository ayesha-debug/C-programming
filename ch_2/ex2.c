/*Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.*/
/*
 * Name 	:Sk.Ayesha
 * Date 	:9-7-2024
 * Modified Date:9-7-2024
 */

/*Required Header Files*/
#include<stdio.h>

/*Required Macros*/
#define limit 7

int main()
{
	char ch;
	int input = 0;
	char s[100];

	while(input < limit)
	{
		ch = getchar();
		
		if(ch == '\n')
			break;
		if(ch == EOF)
			break;

		s[input] = ch;
		input++;
	}
	s[input] = '\0';
	printf("%s",s);
}
	
/*End of the Program*/
