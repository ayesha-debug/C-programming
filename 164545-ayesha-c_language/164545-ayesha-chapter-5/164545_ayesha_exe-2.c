/* Example -2 
* This program extends atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed 
* exponent.
* 
* Steps:
* 1. Include necessary header files for input/output and general functions.
* 2. Define constants for input string length.
* 3. Declare function prototypes for conversion functions.
* 4. Implement the main function:
*    a. Prompt the user for input and read a string representation of a floating-point number.
*    b. Call the my_atof function to convert the input string to a double.
*    c. Print the converted floating-point number.
*    d. Ask the user if they want to check another string, and repeat if they choose to.
* 5. Implement the my_atof function:
*    a. Convert the input string to a double, handling both standard decimal and scientific notation.
*    b. Return the converted floating-point value, considering the sign and exponent.
* 
* Sample Inputs and Outputs:
* Input: 23.45     Output: 23.450000
* Input: 12       Output: 12.000000
* Input: -12.456  Output: -12.456000
* 
* Author: Sk. Ayesha
* Created: 8 July, 2024
* Modified: 16 July, 2024
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>  // Used for printf and getchar functions
#include <math.h>   // Used for mathematical functions 
#include <stdlib.h> // Used for general purpose functions (e.g., atoi )

/** MACRO DEFINITIONS */
#define RANGE 100  // Define a constant for the maximum input string length

/** FUNCTION PROTOTYPES */
double my_atof(char *);  // Function prototype for my_atof to convert string to float

/** MAIN PROGRAM */
/* main(): 
 * Purpose: This function serves as the entry point for the program. 
 * It continuously accepts a string representation of a floating-point number from the user, 
 * converts it to a double using the my_atof function, and prints the result.
 * The user can choose to repeat the process or exit the program.
 * 
 * Author: Sk. Ayesha
 * Created: 8 July, 2024
 * Modified: 16 July, 2024
 */
int main() 
{
    double Dresult;  // Variable to store the converted floating-point number
    char Cinput[RANGE];  // Array to store the input string
    int Iindex = 0;  // Index for the input string
    char Cresponse;  // Variable for user response to continue checking another string

    do {
        Iindex = 0;  // Step 1: Reset index for new input
        while ((Cinput[Iindex] = getchar()) != '\n')  // Step 2: Read characters until newline
            Iindex++;  // Increment index for each character
        Cinput[Iindex] = '\0';  // Step 3: Null-terminate the string

        Dresult = my_atof(Cinput);  // Step 4: Call my_atof to convert the string to float
        printf("x = %lf\n", Dresult);  // Step 5: Print the converted floating-point value
        
        printf("Do you want to check for another string? (y / n)\n");  // Step 6: Prompt user to continue
        scanf(" %c", &Cresponse);  // Step 7: Read user response; added space before %c to skip newline
        while (getchar() != '\n');  // Step 8: Clear input buffer to avoid issues with subsequent input
    } while (Cresponse == 'y' || Cresponse == 'Y');  // Step 9: Repeat if user wants to continue
}
/* End of main() */

/* my_atof(): Converts string to float with scientific notation handling
 * Purpose: This function takes a string representation of a floating-point number (including scientific notation) 
 * and converts it into a double-precision floating-point number. It handles both standard decimal notation and 
 * scientific notation, including optional signs for the number and exponent.
 * 
 * Author: Sk. Ayesha
 * Created: 8 July, 2024
 * Modified: 16 July, 2024
 */
double my_atof(char *p) 
{
    int Ipos = 0, Iexp = 0, Isign = 1;  // Step 1: Initialize position (Ipos), exponent (Iexp), and sign (Isign)
    double Dsum2 = 0, Dsum1 = 0, Dfactor = 0.1;  // Step 2: Initialize sums for integer (Dsum1) and fractional (Dsum2) parts, and factor for decimal conversion

    // Check for sign at the beginning
    if ((p[0] == '-') || (p[0] == '+')) 
    {
        Ipos = 1;  // Step 3: Move position past the sign
    }

    // Convert input into float up to decimal point
    for (; p[Ipos] != 'e' && p[Ipos] != 'E' && (p[Ipos] != '.') && p[Ipos] != '\0'; Ipos++) 
    {
        if ((p[Ipos] >= '0') && (p[Ipos] <= '9')) 
	{
            Dsum1 = Dsum1 * 10 + (p[Ipos] - '0');  // Step 4: Build integer part
        } 
	else 
	{
            return 0;  // Return 0 for invalid input
        }
    }

    // Convert string after decimal point into float
    if (p[Ipos] == '.') 
    {
        Ipos++;  // Step 5: Move past the decimal point
        for (; p[Ipos] != 'e' && p[Ipos] != 'E' && p[Ipos] != '\0'; Ipos++, Dfactor *= 0.1) 
	{
            if ((p[Ipos] >= '0') && (p[Ipos] <= '9')) 
	    {
                Dsum2 = Dsum2 + Dfactor * (p[Ipos] - '0');  // Step 6: Build fractional part
            }
	    else
	    {
                return 0;  // Return 0 for invalid input
            }
        }
    }

    double Dresult = Dsum1 + Dsum2;  // Step 7: Combine integer and fractional parts

    // If it is in exponential form
    if (p[Ipos] == 'e' || p[Ipos] == 'E') 
    {
        Ipos++;  // Step 8: Move past 'e' or 'E'
        
        // Check for sign of exponent
        if (p[Ipos] == '-') 
	{
            Isign = -1;  // Step 9: Set sign to negative
            Ipos++;  // Move past the sign
        }
       	else if (p[Ipos] == '+') 
	{
            Ipos++;  // Step 10: Move past the sign
        }

        // Build exponent value
        for (; p[Ipos] != '\0'; Ipos++) 
	{
            if ((p[Ipos] >= '0') && (p[Ipos] <= '9')) 
	    {
                Iexp = Iexp * 10 + (p[Ipos] - '0');  // Step 11: Construct exponent value
            }
	    else 
	    {
                return 0;  // Return 0 for invalid input
            }
        }

        // Apply the exponent to the result
        if (Isign == 1) 
	{  // Step 12: If exponent sign is positive
            for (int I = 0; I < Iexp; I++) 
	    {
                Dresult *= 10;  // Multiply for positive exponent
            }
        } 
	else
       	{  // Step 13: If exponent sign is negative
            for (int I = 0; I < Iexp; I++) 
	    {
                Dresult /= 10;  // Divide for negative exponent
            }
        }
    }

    // Step 14: Return the result with appropriate sign
    return (p[0] == '-') ? -Dresult : Dresult;  // Returns negative value if input starts with '-'
}
/* end of my_atof() */

