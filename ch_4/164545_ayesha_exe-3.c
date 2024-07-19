/*Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.
 * Author: Sk.Ayesha
 * Created: 16 -07-2024
 * Modified: 16 -07 2024
 * */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */
#define BUFSIZE 100 /* buffer size for ungetch */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */

int getop(char []);
int sp = 0;               /* next free stack position */
double val[MAXVAL];       /* value stack */

void push(double);
double pop(void);
int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int bufp = 0;      /* next free position in buf */

/* reverse Polish calculator */
int main()
{
    int type, temp;
    double op2, op1;
    char s[MAXOP];

    // Loop to get input and perform operations
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));  // If the token is a number, push it onto the stack
                break;
            case '+':
                push(pop() + pop());  // Addition operation
                break;
            case '*':
                push(pop() * pop());  // Multiplication operation
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);    // Subtraction operation
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);  // Division operation
                else
                                        printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 > 0.0 && op1 >= 0.0)
                    push((int)op1 % (int)op2);  // Modulo operation with positive operands
                else if (op2 != 0.0 && op1 < 0.0) {
                    temp = (int)op1 % (int)op2;  // Modulo operation with negative dividend
                    if (temp < 0)
                        push(temp + op2);        // Adjusting result to be positive
                }
                else if (op2 < 0.0 && op1 > 0.0) {
                    temp = (int)op1 % (int)op2;  // Modulo operation with negative divisor
                    if (temp > op2)
                        push(temp + op2);        // Adjusting result to be positive
                }
                else
                    printf("error: zero divisor\n");
                                                             break;
            case '\n':
                printf("\t%.8g\n", pop());  // Print the result
                break;
            default:
                printf("error: unknown command %s\n", s);  // Error for unknown command
                break;
        }
    }
    return 0;
}
                      
