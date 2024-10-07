/*This program is to modify   undcl so that it does not add redundant parentheses to declarations

 * Author: Sk.Ayesha
 * Created: 1 Aug , 2024
 * Modified:1 Aug, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/** MACRO DEFINITIONS */
#define MAXTOKEN 1000
#define PARENS 1
#define BRACKETS 2
#define NAME 3

char token[MAXTOKEN];    /* Last token string */
char out[1000];          /* Output declaration */
int tokentype;           /* Type of last token */

int gettoken(void);      /* Returns the next token */

/* MAIN PROGRAM */
/*main:  */
int main() {
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token); /* Copy first token to output */

        while ((type = gettoken()) != '\n' && type != EOF) {
            if (type == PARENS || type == BRACKETS) {
                strcat(out, token); /* Append parentheses or brackets */
            } else if (type == '*') {
                sprintf(temp, "(*%s)", out); /* Add * before current declaration */
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out); /* Add name before current declaration */
                strcpy(out, temp);
            } else {
                printf("Invalid input at %s\n", token);
                return 1;
            }
        }
        printf("%s\n", out); /* Print the final declaration */
    }
    return 0;
}

/* gettoken: returns next token */
int gettoken(void) {
    int c;
    char *p = token;

    while ((c = getchar()) == ' ' || c == '\t')  /* Skip spaces and tabs */
        ;

    if (c == '(') {
        if ((c = getchar()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetc(c, stdin);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getchar()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getchar()); )
            *p++ = c;
        *p = '\0';
        ungetc(c, stdin);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}


