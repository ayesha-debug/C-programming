/*EXERCISE 10:Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.*/

/*
 * Author	:Sk.Ayesha
 * Created	:28-06-2024
 * Modified	:28-06-2024
 *
 */

/*Required Header Files*/
#include<stdio.h>


// Function prototype for lower
void lower(char str[]);

int main()
{
    char str[100];

    // Input a string from the user
    scanf("%[^\n]s", str);

    // Call the lower function to convert uppercase letters to lowercase
    lower(str);

    // Print the converted string
    printf("%s\n", str);

    return 0;
}

// Function to convert uppercase letters to lowercase using a conditional expression
void lower(char str[])
{
    int i;

    // Loop through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // If the character is an uppercase letter (ASCII range 65 to 90),
        // convert it to lowercase by adding 32 to its ASCII value
        // Otherwise, leave the character unchanged
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] + 32) : str[i];
    }
} 
