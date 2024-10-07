/*Find the word count in the string*/
#include<stdio.h>
#define Max 20
int main()
{
	char str[Max];
	char input;
	printf("ENTER THE STRING\n");
	int max = Max;
	int start = 0,ends,word_count = 0,in_word = 0;
	for(ends = max;max >= ends && ((input = getchar()) != EOF && input != '\n');ends--)
	{
		str[start++] = input;
		if(input == ' ' || input == '\t' || input == '\n' )
		{
	             in_word = 0;
		}
		else if (!in_word)
		{
			word_count++;
			in_word = 1;
		}

	}
       str[start++] = '\0';

	printf("length of the string is %d\n",start);
	printf("word count is %d\n",word_count);
}
