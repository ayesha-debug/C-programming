/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function 
for conversion.*/

/*
 *
*Author		:Ayesha
*Created Date	:23:07:2024
*Modified Data  :23:07:2024
*/

/* Header Files */
#include<stdio.h>

/*function prototypes*/
void function1(int,float);

/*Main function starts here*/
int main()
{
        float upper,lower,celsius,fahr;
	int steps=20;
	// Interval steps for temperature conversion
	function1(steps,celsius);
}
/*main function ends here*/

/* Function to print the temperature conversion table */
void function1(int steps1,float celsius)
{
	float fahr;
        for(celsius =300;celsius >= 0;celsius=celsius-steps1)
        {
                fahr=((celsius*9/5)+32);
                printf("%2.0f c   %2.0f f\n",celsius,fahr);
                //celsius =celsius-steps;
        }

}

/*End of the program*/
