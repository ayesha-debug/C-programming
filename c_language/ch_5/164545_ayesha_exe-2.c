/*Example-2:Write a function getfloat, the floating-point analog of getint. What type does getfloat return as its function value?*/
/*
 * Author               :Sk.Ayesha
 *Created               :15-07-2024
 *Modified              :15-07-2024
 *
 */

/*Required Header Files*/
#include<stdio.h>
int buffer = 0;

int getfloat(float *number)
{
	int input,sign;
	while(isspace (input = getch()));

	if(!isdigit(input) && input != EOF && input != '+' && input != '-')
	{
		ungetch(input);
		return 0;
		
        }
}		
		
		


/*Main function starts here*/
int main()
{
	float num;
	int result;
	result = getfloat(&num);
	if(result != 0)
	{
		printf("It is a valid floating point number - %f\n",num);
	}
	else
	{
		printf("It is a invalid floating point number\n");
	}
}
/*Main function ends here*/
