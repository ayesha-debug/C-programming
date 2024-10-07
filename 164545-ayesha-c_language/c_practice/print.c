/*Basic printing string*/
#include<stdio.h>
#define Max 20
int main()
{
    char str[Max];
    char input;
    int start = 0,ends = 0;
    int max = Max;
    printf("Enter the string\n");
    for(ends = max;((input = getchar()) != EOF && input != '\n');max--)
    {
	    str[start++] = input;
	    printf("str[%d] = %c \n",start-1,input);
    }
    if(input == '\n')
    {
	    str[start++] = input;
    }
	    str[start] = '\0';
   printf("\ninput string %s\n",str);
} 
