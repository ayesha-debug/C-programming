/*Example:4 The next program uses the formula of C=(5/9)(F-32) to print the following table of Fahrenheit temperatures and their centigrade or Celsius equivalents:
*/

/* Author      : ayesha
 * created date: 21/06/2024
 * Modified date: 21/06/2024
 */

/* REQUIRED HEADER FILES */
#include<stdio.h>

/* MAIN PROGRAM STRTS HERE*/
int main()
{
	int fahr,upper,lower,steps,celsius ;
		
    /*Initialize the range and step size */
    lower = 0;    
     // Lower limit of the temperature table
    
     upper = 300;    
    // Upper limit of the temperature table
    
      steps = 20;     
    // Step size,steps,celsius;
	
      /*The while loop performs:
       *Initializes fahr to 0.
       *Iterates over the Fahrenheit range from 0 to 300 in steps of 20.
       *Converts each Fahrenheit temperature to its Celsius equivalent.
       *Prints the Fahrenheit and Celsius values.
       *Stops when fahr exceeds 300.
       */
      while(fahr <= upper)
       	{
		celsius = 5*(fahr-32)/9;
		printf("%3d\t%6d\n",fahr,celsius);
		fahr = fahr + steps;
	}
}
/** End of the main function**/
