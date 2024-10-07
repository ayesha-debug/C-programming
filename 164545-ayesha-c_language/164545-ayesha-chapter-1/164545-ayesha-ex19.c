/*Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.*/

/*
 * Name 	:Sk.Ayesha
 * Date 	:4.07.2024
 * Modified Date:4.07.2024
 *
 */

/*HEADER FILES*/
#include<stdio.h>

/*Function Prototype*/
void reverse(char*);

int main()
{
	char ch;
	char rev_char[50];
	int i = 0;
	while((ch = getchar()) != EOF)
	{
		if(ch != '\n')
		{
		 rev_char[i++] = ch;
		}
		else
		{
			rev_char[i] = '\0';
		        reverse(rev_char);
	                printf("%s\n",rev_char);
			i = 0;
		}
	}
}

void reverse(char* s)
{
	int i,j;
	char temp;
	for(j = 0;s[j] != '\0';j++);
	j--;
	for(i = 0;i < j;i++,j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}



