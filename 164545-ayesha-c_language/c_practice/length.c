/*Find the length of the string*/
#include<stdio.h>
#define Max 20
int main()
{
	char str[Max];
	char input;
	printf("ENTER THE STRING\n");
	int max = Max;
	int start = 0,ends;
	for(ends = max;max >= ends && ((input = getchar()) != EOF && input != '\n');ends--)
	{
		str[start++] = input;
		printf("str[%d] = %c\n",start-1,input);
	}
	str[start++] = '\0';

	printf("length of the string is %d",start);
}
