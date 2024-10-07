#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Required Macros */
#define BUFSIZE 100
#define MAXVAL 100

/* Global variables */
int sp = 0;              // Next free stack position
double val[MAXVAL];      // Value stack
char buf[BUFSIZE];       // Buffer for ungetch
int bufp = 0;            // Next free position in buf

/* Function declarations */
void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

/* Main Function */
/* Implements a reverse Polish notation calculator */
int main() {
    int type;
    char s[BUFSIZE];
    double op2;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case '0': push(atof(s)); break;
            case '+': push(pop() + pop()); break;
            case '-': op2 = pop(); push(pop() - op2); break;
            case '*': push(pop() * pop()); break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero division\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* getop Function */
/* Reads the next operator or operand from input */
int getop(char s[]) {
    int input, i = 0;

    // Skip whitespace
    while ((s[0] = input = getch()) == ' ' || input == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(input) && input != '.' && input != '-') {
        return input; // Not a number
    }

    if (input == '-') {
        if (isdigit(input = getch()) || input == '.')
            s[++i] = input; // Negative number
        else {
            if (input != EOF)
                ungetch(input);
            return '-'; // Minus sign
        }
    } else {
        input = s[i];
    }

    if (isdigit(input)) // Collect integer part
        while (isdigit(s[++i] = input = getch()))
            ;

    if (input == '.') // Collect fraction part
        while (isdigit(s[++i] = input = getch()))
            ;

    s[i] = '\0';
    if (input != EOF)
        ungetch(input);
    return '0'; // Signal that a number was found
}

/* push Function */
/* Pushes a value onto the stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full\n");
}

/* pop Function */
/* Pops and returns a value from the stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

/* getch Function */
/* Gets a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch Function */
/* Pushes character back on input */
void ungetch(int input) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = input;
}

