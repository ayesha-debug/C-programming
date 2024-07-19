/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines.*/

/*
 * Author         : Sk.Ayesha
 * Created Date   : 23:07:2024
 * Modified Date  : 23:07:2024
 */

/* Header Files */
/*
 * Author         : Sk.Ayesha
 * Created Date   : 23:07:2024
 * Modified Date  : 23:07:2024
 */

/* Header Files */
#include <stdio.h>

/* Required macros */
#define MAXLINE 1000   // Maximum input line size

/* Function prototypes */
int getLine(char line[], int maxline);
void trimTrailingBlanks(char line[]);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) {
        trimTrailingBlanks(line);
        if (line[0] != '\0') {
            printf("%s", line);
        }
    }

    return 0;
}

/* Function to read a line into `line` and return its length */
int getLine(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i++] = c;
    }
    
    line[i] = '\0';

    return i;
}

/* Function to remove trailing blanks and tabs from a line */
void trimTrailingBlanks(char line[]) {
    int i;

    for (i = 0; line[i] != '\0'; ++i)
        ;

    // Move back to the last non-blank character
    while (i > 0 && (line[i-1] == ' ' || line[i-1] == '\t' || line[i-1] == '\n')) {
        --i;
    }

    line[i] = '\0';
}
