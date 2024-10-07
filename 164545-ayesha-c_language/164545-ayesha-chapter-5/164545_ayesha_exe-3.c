/*
 * Example:3 This program implements a function to concatenate two strings,
 * similar to the strcat function shown in Chapter 2.
 * my_strcat(s, t) copies the string t to the end of s.
 */

/*
 * Main Steps of the Code:
 * 1. Declare character arrays for the source and destination strings.
 * 2. Use a do-while loop to allow the user to concatenate strings multiple times.
 * 3. Prompt the user to enter the source string and read it into the array.
 * 4. Validate the first character of the source string; set to null if not alphabetic.
 * 5. Prompt the user to enter the destination string and read it into the array.
 * 6. Validate the first character of the destination string; set a default if not alphabetic.
 * 7. Call the my_strcat function to concatenate the destination string to the source string.
 * 8. Output the concatenated string.
 * 9. Ask the user if they want to repeat the process and continue based on their input.
 */

/*
 * Author       : Sk. Ayesha
 * Created      : 1-08-2024
 * Modified     : 1-08-2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>  // Provides functionalities for input and output operations
#include <ctype.h>  // Includes functions for character handling, such as isalpha

/** MACRO DEFINITIONS */
#define WORDS 100  // Defines the maximum length for input strings

/** FUNCTION PROTOTYPES */
void my_strcat(char*, char*);  // Declares the my_strcat function for concatenating strings

/** MAIN PROGRAM */
/** main: Accepts input from the user and calls the my_strcat function */
/*
 * Author       : Sk. Ayesha
 * Created      : 1-08-2024
 * Modified     : 1-08-2024
 */
int main() {
    char Csource[WORDS], Cdestination[WORDS];  // Character arrays for storing source and destination strings
    char Cch_1, Cch_2, Ccharacter;  // Variables for reading characters and user choice
    int Iindex_1, Iindex_2;  // Indices for traversing the strings

    /* do-while: To repeatedly ask the user if they want to concatenate strings 
       The loop continues until the user enters 'y' or 'Y' */
    do {
        Iindex_1 = 0;  // Reset index for source string
        Iindex_2 = 0;  // Reset index for destination string
        
        printf("Enter the source string\n");
        /* while: Reads characters until a newline or EOF is encountered 
           It adds characters to the source string array */
        while ((Cch_1 = getchar()) != EOF && Cch_1 != '\n') {
            if (Iindex_1 < WORDS - 1) {  // Checks if there is space in the array
                Csource[Iindex_1++] = Cch_1;  // Adds character to source string
            }
        }
        Csource[Iindex_1] = '\0';  // Null-terminate the string

        // if: Ensures the first character of the source string is alphabetic
        if (!isalpha(Csource[0])) {
            Csource[0] = '\0';  // Sets the first character to null if it is not alphabetic
        }

        printf("Enter the destination string\n");
        /* while: Reads characters until a newline or EOF is encountered 
           It adds characters to the destination string array */
        while ((Cch_2 = getchar()) != EOF && Cch_2 != '\n') {
            if (Iindex_2 < WORDS - 1) {  // Checks if there is space in the array
                Cdestination[Iindex_2++] = Cch_2;  // Adds character to destination string
            }
        }
        Cdestination[Iindex_2] = '\0';  // Null-terminate the string

        // if: Ensures the first character of the destination string is alphabetic
        if (!isalpha(Cdestination[0])) {
            Cdestination[0] = 'a';  // Assigns a default alphabetic character if not
        }

        /* Calling function my_strcat to concatenate strings */
        my_strcat(Csource, Cdestination);  // Concatenates destination string to source string

        // Output the concatenated result
        printf("After string concatenation --> %s\n", Csource);
        printf("Do you want to concatenate another string (y / n)\n");
        scanf(" %c", &Ccharacter);  // Reads user choice for repeating the process
        while ((Cch_1 = getchar()) != '\n');  // Clear input buffer
    } while (Ccharacter == 'y' || Ccharacter == 'Y');  // Loop continues if user inputs 'y' or 'Y'

    return 0;  // Ensure main returns an integer
}
/* End main() */

/* my_strcat(): To concatenate string t to the end of s */
/*
 * Author       : Sk. Ayesha
 * Created      : 1-08-2024
 * Modified     : 1-08-2024
 */
void my_strcat(char *Cs, char *Ct) {
    /* To move to the end of s */
    for (; *Cs != '\0'; *Cs++);  // Traverse to the end of the source string

    // Concatenate t at the end of s
    for (; *Ct != '\0'; Cs++, Ct++) {  // Loop to copy each character from destination to source
        *Cs = *Ct;  // Copy character
    }
    *Cs = '\0';  // Null-terminate the concatenated string
}
/** End my_strcat() */

