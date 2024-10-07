/*This program is to add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal.

 * Author: Sk.Ayesha
 * Created: 1 Aug , 2024
 * Modified:1 Aug, 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000   /* max length of any input line */
char *lineptr[MAXLINES]; /* pointers to text lines */

int get_line(char *s, int lim) ;
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);

/* Function prototype for case-insensitive comparison */
int case_insensitive_cmp(char *s1, char *s2);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;       /* number of input lines read */
    int numeric = 0;  /* 1 if numeric sort */
    int reverse = 0;  /* 1 if reverse sort */
    int fold = 0;     /* 1 if case-insensitive sort */
    
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (*++argv[0]) {
            switch (*argv[0]) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                fold = 1;
                break;
            default:
                printf("Invalid option: -%c\n", *argv[0]);
                return 1;
            }
        }
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        q_sort((void**) lineptr, 0, nlines-1,
               (int (*)(void*, void*))(numeric ? (int (*)(void*, void*))numcmp : (fold ? (int (*)(void*, void*))case_insensitive_cmp : (int (*)(void*, void*))strcmp)), reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* qsort: sort v[left]...v[right] into increasing or decreasing order */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (reverse ? (*comp)(v[i], v[left]) > 0 : (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    q_sort(v, left, last-1, comp, reverse);
    q_sort(v, last+1, right, comp, reverse);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* case_insensitive_cmp: compare s1 and s2 ignoring case */
int case_insensitive_cmp(char *s1, char *s2) {
    return strcasecmp(s1, s2);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* getline: get line into s, return length */
int get_line(char *s, int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* End get_line */

