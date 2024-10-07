/*Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.*/

/*
 * if input is reached to EOf it's value is 0 ,if it is not reached it's value is 1
 * press cntrl d to reach the EOF
 */

/*
 * Author  	:Sk.Ayesha
 * Created	:21-06-2024
 * Modified	:21-06-2024
*/

/*Header Files*/

#include <stdio.h> 

/*Main Function starts Here*/

int main() 
{
    int input;


     // Read input until EOF is encountered
    while ((input = getchar()) != EOF) 
    {
        printf("getchar() != EOF: %d\n", input != EOF);
    }

      // Notify that EOF has been reached
    printf("EOF reached.\n");
    return 0;
}


/*End of the program*/




