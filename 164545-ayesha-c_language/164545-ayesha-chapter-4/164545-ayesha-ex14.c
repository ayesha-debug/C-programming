/*
* This program is to define a macro swap(t,x,y) that interchanges two arguments of type t. 
(Block structure will help.)programming standards
* Author: Sk.Ayesha
* Created: 4 July, 2024
* Modified:4 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
/* swapping using macro */
#define SWAP(x,y,t)\
{\
	t temp;\
	temp=x;\
	x=y;\
	y=temp;\
}

/** FUNCTION PROTOTYPES */
/** MAIN PROGRAM */
/** main: Accept inputa and calls macro definition */
int main(){
char a,b;
printf("Enter a and b \n");
scanf("%c %c",&a,&b);
/* calling macro */
SWAP(a,b,char);
printf("a=%c b=%c\n",a,b);
}
/* End main() */

