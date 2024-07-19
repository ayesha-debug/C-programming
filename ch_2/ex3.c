/*Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.*/

/*
 * Name 	:Sk.Ayesha
 * Date 	:10-07-2024
 * Modified Date:10-07-2024
 * 
 */

/*Required Header Files*/
#include<stdio.h>

/*Required function prototypes*/
//int hoti(const char);


/*Hexa decimal to integer conversion function*/
int hoti(const char s[])
{
	int i = 0,n = 0;

	if(s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
	{
		i += 2;
	}
	
	
		while(s[i] != '\0')
	        {
		if(s[i] >= '0' && s[i] <= '9')
		{
			n = 16 * n +(s[i] - '0');

		}
		else if(s[i] >= 'a' && s[i] <= 'f')
		{
			n = 16 * n +(s[i] - 'a' + 10);
		}
		else if((s[i] >= 'A') && (s[i] <= 'F'))
		{
			n = 16 * n +(s[i] - 'A' + 10);
		}
		else
		{
			return -1;
		}
	         i++;
	     }
	return n;
}


int main()
{
	int output;
	const char *hexa_dec = "0x2af";
        output = hoti(hexa_dec);
	printf("%d",output);
}
/*End of the program*/
