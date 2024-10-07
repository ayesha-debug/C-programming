/* This program is to expand dcl to handle declarations with function argument types, qualifiers 
like const, and so on. 

 * Author: Sk.Ayesha
 * Created: 1 Aug , 2024
 * Modified:1 Aug, 2024
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, CONST };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char out[1000];             /* output string */

int main() {
    while (gettoken() != EOF) { /* 1st token on line */
        strcpy(datatype, token); /* is the datatype */
        out[0] = '\0';
        dcl(); /* parse rest of line */
        if (tokentype != '\n' && tokentype != EOF)
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* gettoken: return next token */
int gettoken(void) {
    int c;
    void ungetch(int);
    int getch(void);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t') /* skip blanks and tabs */
        ;

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()) || c == '_'; )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        if (strcmp(token, "const") == 0)
            return tokentype = CONST;
        return tokentype = NAME;
    } else
        return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) {   /* get a (possibly pushed-back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* dcl: parse a declarator */
void dcl(void) {
    int ns;

    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void) {
    int type;

    if (tokentype == '(') {  /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME) {  /* variable name */
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
        return; // Exit early on error
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS || type == CONST) {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else if (type == BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        } else if (type == CONST) {
            strcat(out, " const");
        }
    }

    // Handle any additional tokens or errors
    if (type != '\n' && type != EOF) {
        printf("error: unexpected token '%s'\n", token);
    }
}
/* End of dirdcl */

