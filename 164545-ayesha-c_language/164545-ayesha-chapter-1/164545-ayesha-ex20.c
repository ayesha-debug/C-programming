/*This program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
input is this\tis\ta\ttest
Name : Sk.Ayesha
created :1 July,2024
Modified:1 July,2024
*/


#include <stdio.h> 
// Required for input/output functions

/** MACRO DEFINITIONS **/
#define TAB 4
// Number of spaces for each tab stop

/* MAIN PROGRAM */
/**
 * Brief: The main function replaces each tab character in the input with a fixed number of spaces.
 * 
 * Return: int Returns 0 if the program completes successfully.
 */
int main() 
{
    char Cch;  // Character for input
    int Icount = 0;  // Count to track the current column position
    int Iindex = 0;  // Index for looping through the input string
    char Cstr[100];  // Buffer to store input string

    // Read the input string until EOF
    while ((Cch = getchar()) != EOF) 
    {
        Cstr[Iindex++] = Cch;
    }
    Cstr[Iindex] = '\0';  // Null-terminate the input string

    // Iterate through the input string
    for (Iindex = 0; Cstr[Iindex] != '\0'; Iindex++) 
    {
        if (Cstr[Iindex] == '\\' && Cstr[Iindex + 1] == 't') 
	{
            // Replace '\t' with spaces
            int Ispaces = TAB - (Icount % TAB);
            while (Ispaces > 0) {
                putchar('*');
                --Ispaces;
                Icount++;
            }
            Iindex++;  // Skip the 't' character in '\t'
       }
       	else
       {
            // Write the character to output
            putchar(Cstr[Iindex]);
            Icount++;
            if (Cstr[Iindex] == '\n') {
                Icount = 0;  // Reset count for a new line
            }
        }
    }

    return 0;  // Successful execution
}

