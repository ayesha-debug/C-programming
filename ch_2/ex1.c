/*Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printig appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types*/

/*Name 		:Sk.Ayesha
 * Date		:9.07.2024
 * Modified Date:9:07:2024
 */

/*Required Header Files*/
#include<stdio.h>

int main()
{
	char character;
	int integer;
	short int short_int;
	long int long_int;
	printf("size of character is %ld\n",sizeof(character));
	printf("size of integer is %ld\n",sizeof(integer));
	printf("size of short_int is %ld\n",sizeof(short_int));
	printf("size of long_int is %ld\n",sizeof(long_int));
}

/*END OF THE PROGRAM*/
