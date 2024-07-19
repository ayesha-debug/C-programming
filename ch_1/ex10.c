/*Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */

/*
 * Name         :Sk.Ayesha
 * Created      :22-06-2024
 * modified     :22-06-2024
 */

/*Header files*/
#include <stdio.h>

/*Main function starts Here*/
int main() 
{
    char input;

    // Loop to read characters until EOF
    while ((input = getchar()) != EOF) 
    {
        switch(input) 
	{
            case '\t':printf("\\t");  
		      // Replace tab with visible representation
                      break;
            case '\b':printf("\\b");  
		      // Replace backspace with visible representation
                      break;
            case '\\':  printf("\\\\"); 
			// Replace backslash with visible representation
                      break;
            defauly:  printf("%c", input); 
		      // Print other characters as they are
        }
    }

}

/*End of the main Function*/

