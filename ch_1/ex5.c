/*Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

*Author		:Ayesha
*Created Date	:21:06:2024
*Modified Data  :21:06:2024
*/

/* REQUIRED HEADER FILES */
#include<stdio.h>



/* Main Function Starts Here*/
int main()
{
	float upper,lower,celsius,fahr,steps=20;

	/* Print the header of the table */
    printf("Celsius to Fahrenheit table (Reverse Order)\n");
    printf("------------------------------------------\n");
	
    /*	the for loop iterates:
	*Initializes celsius to 300.
	*Iterates over the Celsius range from 300 down to 0 in steps of 20.
	*Converts each Celsius temperature to its Fahrenheit equivalent.
	*Prints the Celsius and Fahrenheit values.
	*Stops when celsius is less than 0.
	*This produces a table of Celsius to Fahrenheit conversions in reverse order.
	*/
    for(celsius =300;celsius >= 0;celsius=celsius-steps)
	{
		fahr=((celsius*9/5)+32);
		printf("%2.0f c   %2.0f f\n",celsius,fahr);
	}
}

/*End of the program*/
