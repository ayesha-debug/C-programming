//Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
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

    while ((input = getchar()) != EOF) 
    {
        printf("getchar() != EOF evaluates to: %d\n", input != EOF);
    }

    printf("End of input reached. getchar() != EOF evaluates to: %d\n", input != EOF);

}

/*End of the program*/




