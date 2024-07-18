/*Example-1:As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.*/
/*
 * Author		:Sk.Ayesha
 *Created		:15-07-2024
 *Modified		:15-07-2024
 *
 */

/*Required Header Files*/
#include <stdio.h>
#include <ctype.h>


/* Function Declarations */
int getint(int *pn);
void ungetch(int);
int getch(void);

/*Main function starts Here*/
int main() 
{
    int num;
    int result = getint(&num);

    if (result != 0) 
    {
        printf("Input is an integer: %d\n", num);
    } 
    else 
    {
        printf("Input is not a valid integer\n");
    }

    return 0;
}


int buf = 0; 
// buffer for ungetch

/* getch: get a (possibly pushed-back) character */
int getch(void) 
{
    int c;
    if (buf != 0) 
    {
        c = buf;
        buf = 0;
    }
    else
    {
        c = getchar();
    }
    return c;
}


/* ungetch: push character back on input */
void ungetch(int c)
{ 
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}


/*getin function starts here*/
/* getint: get next integer from input into *pn */
int getint(int *pn) 
{
    int c, sign;

    while (isspace(c = getch())) 
	    // skip white space
        ;

      /* Check if the input is not a number */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') 
    {
        ungetch(c); 
	// it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') 
    {
        int temp = c;
        c = getch();
        if (!isdigit(c))
       	{
            ungetch(c);
            ungetch(temp);
            return 0;
        }
    }

     /* Accumulate digits to form the integer */
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * (*pn) + (c - '0');
    }
     *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
/*End of the getin function*/
