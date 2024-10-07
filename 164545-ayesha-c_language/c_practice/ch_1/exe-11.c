/* count lines, words, and characters in input */
/*program to count the words in a given line*/

#include<stdio.h>
int main()
{
	char input;
	int word_count = 0,line_count = 0,character_count = 0,in_word = 0,prev_input = 0,empty_input = 0;
	while((input = getchar()) != EOF)
	{
		if(input != ' ' && input != '\n' && input != '\t')
		{
			character_count++;
			empty_input = 1;
		}
		
		if(input == '\n')
		{
			if(empty_input)
			{
				line_count++;
				empty_input = 0;
			}
	       }

	       if(prev_input == 1 && input != '\n')
	       {
		       line_count++;
	       }
	       prev_input = input;
	}
	printf("\ncharacter count --> %d\nline count --> %d\n",character_count,line_count);
}


