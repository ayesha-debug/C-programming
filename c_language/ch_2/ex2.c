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
	int i = 0;
	char s[100];

	while(i < limit)
	{
		ch = getchar();
		
		if(ch == '\n')
			break;
		if(ch == EOF)
			break;

		s[i] = ch;
		i++;
	}
	s[i] = '\0';
	printf("%s",s);
}
	
/*End of the Program*/
