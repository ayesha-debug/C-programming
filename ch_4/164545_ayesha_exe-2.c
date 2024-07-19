/*Exercise 4-2. Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 * Author:Sk.Ayesha
 * Created: 9-07- 2024
 * Modified: 9-07- 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/*MACRO DEFINITIONS */
#define MAXLEN 500 // Maximum length of the input line

// Function prototypes
int get_line(char line[], unsigned int max_line_len);
double atof(char s[]);

/*
 * MAIN(): main function read one line from stdin by calling get_line function and convert that string to float equalant value
 * */
int main(void)
{
        char line[MAXLEN];

        // Get a line of input from the user
        get_line(line, MAXLEN);
        // Print the input line
        printf("%s\n", line);
        // Convert the input line to a floating-point number and print it
        printf("%f\n", atof(line));

        return 0;
/**
 * get_line(): This function reads one line from stdin and return i value.
 * */
int get_line(char line[], unsigned int max_line_len)
{
        int i = 0;
        int c;

        // Read characters until end of line or maximum length is reached
        while (i < max_line_len - 1 && (c = getchar()) != '\n' && c != EOF)
        {
                line[i++] = c;
        }

        // Null-terminate the string
        line[i] = '\0';

        return i;
}

/**
 * atof(): This function takes string as an argument and that string into a floating value
