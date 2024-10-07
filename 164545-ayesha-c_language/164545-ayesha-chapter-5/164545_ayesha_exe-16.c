/*This program is to add the -d (``directory order'') option, which makes comparisons only on letters, numbers and blanks. Make sure it works in conjunction with -f.

 * Author:Sk.Ayesha
 * Created: 1 Aug , 2024
 * Modified:1 Aug, 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000   /* max length of any input line */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int dircmp(char *, char *);

int get_line(char *s, int lim) ;
int case_insensitive_cmp(char *s1, char *s2) ;
/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;       /* number of input lines read */
    int numeric = 0;  /* 1 if numeric sort */
    int reverse = 0;  /* 1 if reverse sort */
    int fold = 0;     /* 1 if case-insensitive sort */
    int directory = 0;/* 1 if directory order sort */
    
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
            case 'd':
                directory = 1;
                break;
            default:
                printf("Invalid option: -%c\n", *argv[0]);
                return 1;
            }
        }
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        int (*compare)(void *, void *) = (int (*)(void *, void *))strcmp;

        if (numeric) {
            compare = (int (*)(void *, void *))numcmp;
        } else if (directory) {
            compare = (int (*)(void *, void *))dircmp;
        } else if (fold) {
            compare = (int (*)(void *, void *))case_insensitive_cmp;
        }

        q_sort((void**) lineptr, 0, nlines-1, compare, reverse);
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

/* dircmp: compare s1 and s2 in directory order (only letters, numbers, and blanks) */
int dircmp(char *s1, char *s2) {
    while (*s1 && *s2) {
        while (*s1 && !isalnum(*s1) && *s1 != ' ') s1++;
        while (*s2 && !isalnum(*s2) && *s2 != ' ') s2++;
        if (tolower(*s1) != tolower(*s2))
            return tolower(*s1) - tolower(*s2);
        if (*s1) s1++;
        if (*s2) s2++;
    }
    return tolower(*s1) - tolower(*s2);
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
/*End of get_line */

