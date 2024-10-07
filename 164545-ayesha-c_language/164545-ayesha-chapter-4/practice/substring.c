/*String to check substring is present or not*/

#include<stdio.h>
#define max 100

void user_input(char *input_str, int Max);
int search_str(char *Main_str,char *Sub_str);
int main()
{
	char main_str[max];
	char sub_str[max];
	user_input(main_str, max);
	user_input(sub_str, max);
	search_str(main_str,sub_str);
	printf("Main string is %s\n", main_str);
	printf("sub string is %s\n", sub_str);
	return 0;
}

int search_str(char Main_str[],char Sub_str[])
{
	int upper,lower;
	for(upper = 0;Main_str[upper];upper++)
	{
		if(Main_str[upper] == Sub_str[0])
		{
			for(lower = 1;Sub_str[lower];lower++)
			{
				if( Sub_str[lower] != Main_str[upper+lower])
				{
					break;
				}

			        Sub_str[lower] = '\0';
				printf("sub string is present in %s\n",Main_str + upper); 
			}
		}
	}
}

    







void user_input(char input_str[], int Max)
{
	char input;
	int index = 0,upper;
	for( upper = Max; upper > 0 && ((input = getchar()) != EOF && input != '\n');upper--)
	{
	    input_str[index++] = input;
	}
	    input_str[index] = '\0';
	    
}
