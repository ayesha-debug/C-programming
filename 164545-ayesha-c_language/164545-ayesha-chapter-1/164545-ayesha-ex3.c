/*. Write a program to print the corresponding Celsius to Fahrenheit table.*/

/*
 * Author       :Sk.Ayesha
 * Created      :21:06:2024
 *Modified      : 21.06.2024
 */


/*Required Header Files*/
#include <stdio.h>

/*Main function starts Here*/
int main()
{
	float upp,low,cel,steps=20,fah;
                                                                
	/*The for loop runs from 0 to 100 in steps of 20, 
	 * converting each Celsius value to its Fahrenheit equivalent and printing the result. 
	 * This creates a table of Celsius to Fahrenheit conversions for the specified range.
	 */
	
	for( cel=0;cel<100;cel=cel+steps)
	{
		fah=((cel*9/5)+32);
		printf("%2.f c %3.f f\n",cel,fah);
	}
}
/*End of the Main Program*/
