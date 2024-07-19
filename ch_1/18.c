//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

/*
 * Name		:Sk.Ayesha
 * Date		:4.07.2024
 * Modified Date:4.07.2024
 *
 */

/*Header files*/
#include<stdio.h>

int main()
{
	char ch;
	char remove[50];
	int i = 0;
	while((ch = getchar()) != EOF)

	{
		remove[i++] = ch;
		if((ch == ' ') || (ch == '\t'))
		{
			i--;
		}
	}
	remove[i+1] = '\0';
	
	int j,k;
	for(j = 0;remove[j] != '\0'; j++)
	{
		if((remove[j] == '\n') && (remove[j+1] == '\n'))
		{
			for(k = j;remove[k];k++)
			{
				remove[k] = remove[k+1];
			        j--;
			}
		}
	}
		printf("%s",remove);
	
}


/*End of the program*/
