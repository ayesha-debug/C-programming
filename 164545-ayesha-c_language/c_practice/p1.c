#include <stdio.h>

int getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int main() {
    char line[100];
    int len;

    printf("Enter a line of text:\n");
    len = getline(line, 100);

    printf("You entered: %s", line);
    printf("Length of line: %d\n", len);

    return 0;
}

