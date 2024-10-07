/*Exercise 4-2. Extend atof to handle scientific notation of the form
 * 123.45e-2
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 *  Example Input: "123.456e-2"
 *  Example Output:1.23456
 * 
 * Author:Sk.Ayesha
 * Created: 23-07- 2024
 * Modified: 23-07- 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
//Provides functions for standard input and output operations.
#include <ctype.h>
//Provides functions for character handling (e.g., checking if a character is a digit or whitespace).
#include<math.h>
//Provides mathematical functions (e.g., power functions).

/*Required Header Files*/
#define max 100
// Define maximum input length

/*Function declarations*/
void get_input(char *Str,int Max);
double atof(const char *str);
// Converts a string to a double-precision floating-point number

int main()
{
	char str[max];
	printf("Enter the input\n");
	 // Get input from user
	get_input(str,max);
	printf("string is %s\n",str);
        
	// Convert string to double and print result
	printf("output of the atof function %f\n",atof(str));
	return 0;
}
 /*
  * function to convert a string to double
  * Purpose: Parses a string representing a floating-point number and returns its double-precision floating-point equivalent.
  *The string can include an optional sign, integer part, decimal point, fractional part, and exponent.
  */
double atof(const char str[])
{
        int outer = 0,exponent,sign,exp_sign;
        double power,var;
	
	/*step 1 -->skip white spaces*/
	while(isspace(str[outer])) outer++;
	
	/*step 2 -->Handle sign*/
        sign = (str[outer] == '-' ) ? -1 : 1;
	// Determine the sign of the number
	if(str[outer] == '+' || str[outer] == '-') outer++;
	// Move past the sign character

	 /* Step 3: Process integer part */
	for(var = 0.0;isdigit(str[outer]);outer++)
	{
		var = 10.0 * var + (str[outer] - '0');
		// Convert digit character to integer and accumulate
	}
	
       /* Step 4: Process fractional part */
	if(str[outer] == '.')outer++;
          // Move past the decimal point	
	for(power = 1.0;isdigit(str[outer]);outer++)
	{
		var = 10.0 * var + (str[outer] - '0');
		// Convert digit character to integer and accumulate
		power *= 10.0;
		// Adjust power of 10 for fractional part
	}
	 var = sign * var / power;
	 // Combine integer and fractional parts, applying sign

	 /* Step 5: Process exponent part */
	if(str[outer] == 'e' || str[outer] == 'E')
	 {
		outer++;
	 // Move past the 'e' or 'E' 
        
	 // Determine the sign of the exponent
	exp_sign = (str[outer] == '-') ? -1 : 1;
	if(str[outer] == '+' || str[outer] == '-')outer++;
         // Move past the exponent sign character

	for(exponent = 0;isdigit(str[outer]);outer++)
	{
	        // Convert exponent characters to integer
        
		exponent = 10 * exponent + (str[outer] - '0');
	}

        // Apply the exponent to the result
	if(exp_sign == -1)
	{
		// Divide by 10^exponent
		var /= pow(10, exponent);
	}
	else
	{
		// Multiply by 10^exponent
		var *= pow(10, exponent);
	}
      }
	// Return the converted double value
	 return var;
}

/* Function to get input from the user
   Reads characters from standard input until a newline or end-of-file is encountered,
   or the maximum length is reached.
   Parameters:
     - str: The array to store the input string.
     - max: The maximum number of characters to read.
   Returns:
     - None (string is modified in place)
*/
void get_input(char Str[],int Max)
{
	int outer,index = 0;
	char input;
	for(outer = Max;outer > 0 && ((input = getchar()) != EOF && input != '\n');outer--)
	{
		Str[index++] = input;
	}
	Str[index++] = '\n';
	//Null-terminates the string to ensure it is properly ended.
}
