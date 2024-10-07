/*
 * This program is to rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop.
 * Author: Sk.Ayesha
 * Created:17 July, 2024
 * Modified:17 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
/** MACRO DEFINITIONS */
#define WORDS 100
#define NUMBER '0'
#define MAX 100
int top=0;
int stk[WORDS];
/** FUNCTION PROTOTYPES */
void get_line(char *s);
 int my_atoi(const char *p);
 char* my_itoa(int,char*);
 void revers(char*);
int strindex(char *s, char *t);
int getop(char*s);
void push(double);
double pop();
/** MAIN PROGRAM */
/** main: Content of main write here to choose a operation to do*/
int main(){
	char s[WORDS],t[WORDS];
	int n,choice,type;

	
   
        printf("Choose a operation:\n");
        printf("1. getline()\n");
        printf("2. atoi()\n");
        printf("3. itoa()\n");
        printf("4. reverse()\n");
	printf("5. strindex()\n");
	printf("6. getop()\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        char ch;
	int i=0;
        /* switch to select a case */
        switch (choice) {
            case 1:
		    /* get_line */
		get_line(s);
		printf("%s \n",s);
		break;
	    case 2:
		/* my_atoi */
		scanf("%s",t);
		int n=my_atoi(t);
		printf("%d\n",n);
		break;
	    case 3:
		/* my _itoa */
                   int num;
		   scanf(" %d",&num);
	       my_itoa( num,s);
		printf("%s",s);
            break;
	    case 4:
	    /* reverse */
	    char*ptr=s;     
	while((ch=getchar())!=EOF)
	{
		*ptr++=ch;
	}
	*ptr='\0';
	          revers(s);
		  printf("%s\n",s);
                break;
	    case 5:
		/* strindex */
		getchar();
		
                int index;
		printf("string \n");
		scanf(" %[^\n]",s);
		printf("match \n");
		scanf(" %[^\n]",t);
		index=strindex(s,t);
		printf("%d",index);
		break;
	    case 6:
		/* getop */
		getchar();
                 double op2;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));  /* Convert string to double and push it onto the stack */
            break;
	    /* Addition */
        case '+':
            push(pop() + pop());
            break;
	    /* multiplication */
        case '*':
            push(pop() * pop());
            break;
	    /* subtraction */
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
	    /* For division */
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Error: division by zero\n");
            break;
	    /* prints data if it is new line by popping element */
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: unknown command %s\n", s);
            break;
        }
    }
    
		break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
	return 0;

}
/* End main() */
void get_line(char *s)
{
  while ((*s = getchar()) != EOF)
  {
    ++s;
  }

  *s = '\0';
}
/* my_atoi():converts string to integer */
 int my_atoi(const char *p)
  {
          int sign=1,sum = 0;

           /* if there is negative symbol */
          if(*p == '-'){
                  p++;
                  sign=-1;
          }
          for(;*p!='\0';p++)
          {
                  if((*p>='0')&&(*p<='9'))
                  sum=sum*10+(*p-48);
                  else{
			  printf("invalid input\n");
                  break;
		  /* exit from loop */
		  }
          }
          return sign*sum;
  }
/*End of my_atoi*/
void revers(char*s){
	    char *start = s;
    char *end = s + strlen(s) - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
char *my_itoa(int num,char*s){
    char *ptr = s;
    int is_negative = 0;

    /* Handle 0 explicitly */
    if (num == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return s;
    }

    /* Handle negative numbers */
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    /* Process individual digits */
    while (num != 0) {
        *ptr++ = (num % 10) + '0';
        num = num / 10;
    }

    /* If number is negative, append '-' */
    if (is_negative) {
        *ptr++ = '-';
    }

    *ptr = '\0';

    /* Reverse the string */
    revers(s);

    return s;
}

int strindex(char *s, char *t) {
    int i, j, k;
    /* strlen : it is used to find length of string */
    int slen = strlen(s);
    int tlen = strlen(t);
    for (i = slen - tlen; i >= 0; i--) {
        for (j = i, k = 0; k < tlen && tolower(s[j]) == tolower( t[k]); j++, k++);
        if (k == tlen) {
                /*return index */
            return i+1;
        }
    }

    /* If substring is not found */
    return -1;
}
/* End of strindex()*/
int getop(char *s)
{
  char c;

  /* Skip blanks (spaces and tabs) */
  while ((*s = c = getchar()) == ' ' || c == '\t')
    ;

  *(s + 1) = '\0';

  /* Not a number */
  if (!isdigit(c) && c != '.')
    return c;

  /* Collect the integer part */
  if (isdigit(c) && c != '.')
    while (isdigit(*(++s) = c = getchar()))
      ;

  /*  Collect the fraction part */
  if (c == '.')
  {
    while (isdigit(*(++s) = c = getchar()))
      ;
  }

  if (c != EOF)
    ungetc(c, stdin);

  *s = '\0';

  return NUMBER;
}
/* push: push f onto value stack */
void push(double f)
{
        if(top == MAX) {
                printf("stack is overflow...\n");
                return;
        }


        stk[top++] = f;
}
/* pop: pop and return top value from stack */
double pop(void )
{
        if(top == 0) {
                printf("stack is underflow...\n");
                return 0.0;
        }

        return stk[--top];
}
/* End of pop */

