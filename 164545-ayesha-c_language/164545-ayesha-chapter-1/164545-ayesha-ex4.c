/*Example:4 The next program uses the formula of C=(5/9)(F-32) to print the following table of Fahrenheit temperatures and their centigrade or Celsius equivalents:
*/
 
/*Example Input: 
 * 40
 *
 * Example Output:
 * Celsius =  40 	 Fahrenheit = 104
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
	float fahr,upper,lower,steps,celsius ;
	 /* Prompt user for Celsius input */
	printf("celsius to fahrenheit\n");
	scanf("%f",&celsius);
		
         /* Convert Celsius to Fahrenheit */	
	  fahr = (9.0/5.0 * celsius)+32.0;
	   /* Display the result */
		printf("celsius = %3.0f\tfahrenheit = %3.0f\n",celsius,fahr);
}
/** End of the main function**/
