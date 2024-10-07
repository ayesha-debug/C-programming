/*Find the charcaters count in the string*/
#include<stdio.h>
#define Max 20
int main()
{
	char str[Max];
	char input;
	printf("ENTER THE STRING\n");
	int max = Max;
	int start = 0,ends,character_count = 0;
	for(ends = max;max >= ends && ((input = getchar()) != EOF && input != '\n');ends--)
	{
		str[start++] = input;
		if(input != EOF || input != '\n' || input != '\t')
		{
			character_count++;
		}
	}
       str[start++] = '\0';

	printf("length of the string is %d\n",start);
	printf("charcter count is %d\n",character_count);
}
