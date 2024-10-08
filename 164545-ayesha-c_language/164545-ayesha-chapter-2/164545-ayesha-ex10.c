/*EXERCISE 10:Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.*/

/*
 * Author	:Sk.Ayesha
 * Created	:28-06-2024
 * Modified	:28-06-2024
 *
 */

/*Required Header Files*/
#include<stdio.h>


/** FUNCTION PROTOTYPES */
char lower(char s);
/** MAIN PROGRAM */
/** main: Accepts */
int main(){
	char character;
	printf("enter  characters\n");
	while((character=getchar())!=EOF&&character!='\n'){
		char upper=lower(character);
	printf("%c",upper);
	}

	return 0;
}
/* End main() */

/** lower: to convert upper case to lower case using conditional expression */
char lower(char s)
{

return((s>='A'&& s<='Z')?(s=s^32):s);

}

