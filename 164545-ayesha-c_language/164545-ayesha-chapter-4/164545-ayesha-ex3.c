/*Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

*Main Function Role:
 *Orchestrates the program flow by calling getop to fetch the next operator or operand, and then using a switch case to perform operations.
Operations:
*If the type is an operator (+, -, *, /), it performs the operation on the top two numbers on the stack and pushes the result.
*If the type is a NUMBER, it converts the string to a number and pushes it onto the stack.
*If the type is a newline (\n), it pops and prints the top value from the stack.*/

/*
 * Author: Sk.Ayesha
 * Created: 29 -07-2024
 * Modified: 29 -07 2024
 * */

/*Required Header Files*/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

/*Required Macros*/
#define BUFSIZE 100
#define MAXVAL 100

/*Gobal variables*/
int sp = 0;
//Next free Stack Position
double val[MAXVAL];
//Value Stack
char buf[BUFSIZE];
//buffre for ungetch
int bufp = 0;
// next free position in buf

/* Function declarations */
void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

/*Main Function Starts Here*/
/*The existing framework includes several key functions: main, push, pop, getop, getch, and ungetch*/
int main()
{
	int type;
	char s[BUFSIZE];
	double op2;

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case '0': push(atof(s));
				  break;
	                case '+':push(pop() + pop());
				 break;
	                case '-':op2 = pop();
				 push(pop() - op2);
				 break;
	                case '*':push(pop() * pop());
				 break;
	                case '/':op2 = pop();
				 if(op2 != 0.0)
					 push(pop() /op2);
				 else
					 printf("error: zero division\n");
				 break;
	                case '%':op2 = pop();
				 if(op2 != 0.0)
					 push(fmod(pop(), op2));
				 else
					 printf("error: zero divisor\n");
				 break;
		      case '\n': printf("\t%.8g\n",pop());
				 break;
			default:
				 printf("Error:unknown command %s\n",s);
				 break;
		}
	}
	return 0;
}



/*Getop Function
Role: Reads the next operator or operand from input.
Operations:
 *Skips whitespace.
 *Returns a character if it's not a digit or decimal point (indicating it's an operator).
 *Reads a number and returns it as a NUMBER.*/
int getop(char s[])
{
	int Input,next;

	/*This loop skips any spaces or tabs. It stops when a non-whitespace character is found and stores it in s[0].*/
	while(s[0] = Input = getchar () == ' ' || Input == '\t');
	s[1] = '\0';

	/*If the character is not a digit, decimal point, or minus sign, it is considered an operator and is returned immediately.*/	
	if (!isdigit(Input) && Input != '.' && Input != '-')
	{
           return Input;
	   //not a number
	}

	int start = 0;
	if(Input == '-')
	{
		
		//If the next character is  a digit and  a decimal point
		if(isdigit(next = getchar()) || next == '.')
		{ 
			s[++start]  = Input = next;
		}	
		else
		{	//It pushes the character back to the input buffer using ungetc.
		     if(next != EOF)
		     {
			     //The function pushes the read character back to the input buffer using ungetch(Input) to ensure it's available for the next function call or processing
			     ungetch(next);
		     
		     // return the minus sign as an operator
		     return '-';
		}
	}
       
        // Collecting integers of a number.
	if(isdigit(Input))
		while(isdigit(s[++start] = Input = getch()));
	//collecting fractional parts
	if(Input == '.')
	        while(isdigit(s[++start] = Input = getch()));
	s[start] = '\0';

	if(Input != EOF)
		ungetch(Input);
	return 0;
	// Signal that a number was found
   
    }
}

/* push Function */
/* Pushes a value onto the stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error : stack full\n");
}

/* pop Function */
/* Pops and returns a value from the stack */
double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("Error : Stack empty\n");
	return 0.0;
	}
}

/* getch Function */
/* Gets a (possibly pushed back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch Function */
/* Pushes character back on input */
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
	
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


