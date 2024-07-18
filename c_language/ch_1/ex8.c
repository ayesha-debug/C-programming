//Exercise 1-8. Write a program to count blanks, tabs, and newlines

/*
 * Author       :Sk.Ayesha
 * Created      :22-06-2024
 * Modified     :22-06-2024
 */

/* Required Header Files */
#include <stdio.h>

/* Main Function Starts Here */
int main() 
{
    int input;
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

// Read characters until EOF is encountered
    while ((input = getchar()) != EOF) 
    {
        if (input == ' ') 
	{
            blanks++;
	    // Increment blanks counter if space is encountered
        } 
	else if (input == '\t') 
	{
            tabs++;
	    // Increment tabs counter if tab is encountered
        } 
	else if (input == '\n')
       	{
            newlines++;
	    // Increment newlines counter if newline is encountered
        }
    }
// Output the counts of blanks, tabs, and newlines
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
/*End of the Main Function*/
