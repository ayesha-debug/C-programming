
/*
 * This program is to write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Author: Sk.Ayesha
 * Created: 16 July, 2024
 * Modified:16 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define WORDS 100

/** FUNCTION PROTOTYPES */
void my_strncat(char *,char*,int);
void my_strncpy(char *,char*,int);
int my_strncmp(char*,char*,int);
/** MAIN PROGRAM */
int main() {
    char s[WORDS], t[WORDS];
    int n, choice;

    printf("Enter the source string: ");
    scanf(" %[^\n]", s);
    printf("Enter the destination string: ");
    scanf(" %s", t);
    printf("Enter a number: ");
    scanf(" %d", &n);

    printf("Choose an operation:\n");
    printf("1. Concatenate strings\n");
    printf("2. Copy string\n");
    printf("3. Compare strings\n");
    scanf(" %d", &choice);

    switch (choice) {
        case 1:
            my_strncat(s, t, n);
            printf("Concatenated string: %s\n", s);
            break;
        case 2:
            my_strncpy(s, t, n);
            printf("Copied string: %s\n", s);
            break;
        case 3: {
            int result = my_strncmp(s, t, n);
            if (result < 0) {
                printf("The first %d characters of '%s' are less than '%s'.\n", n, s, t);
            } else if (result == 0) {
                printf("The first %d characters of '%s' are equal to '%s'.\n", n, s, t);
            } else {
                printf("The first %d characters of '%s' are greater than '%s'.\n", n, s, t);
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

/* my_strncat: To concatenate string t to the end of s using pointers */
void my_strncat(char *s, char *t, int n) {
    /* Move the pointer to the end of string s */
    while (*s) {
        s++;
    }

    /* Append t to the end of s, but only up to n characters */
    while (n-- > 0 && *t) {
        *s = *t;
        s++;
        t++;
    }

    /* Null-terminate the result */
    *s = '\0';
}

/* my_strncpy: To copy up to n characters from t to s using pointers */
void my_strncpy(char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++)) {
        ;
    }

    /* If n is greater than the length of t, fill the remaining with null characters */
    while (n-- > 0) {
        *s++ = '\0';
    }
}

/* my_strncmp: To compare the first n characters of s and t using pointers */
int my_strncmp(char *s, char *t, int n) {
    for (; n > 0; s++, t++, n--) {
        if (*s != *t) {
            return *s - *t;
        }
        if (*s == '\0') {
            return 0;
        }
    }
    return 0;
}
/*End of my_strncmp */

