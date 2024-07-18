#include <stdio.h>
#include <ctype.h>

int buf = 0; // Buffer to store pushed-back character

int getch(void) {
    int c;
    if (buf != 0) {
        c = buf;  // If there is a character in the buffer, use it
        buf = 0;  // Clear the buffer
    } else {
        c = getchar();  // Otherwise, read a character from standard input
    }
    return c;  // Return the character
}

void ungetch(int c) {
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;  // Push character back into the buffer
    }
}

int main(void) {
    int c;

    // Read a character
    printf("Enter a character: ");
    c = getch();
    printf("Read character: %c\n", c);


    // Read the character again
    printf("Character pushed back %c\n",c);
    c = getch();
    printf("Read character again: %c\n", c);

    // Read the next character
    printf("Enter another character: ");
    c = ungetch();
    printf("Read another  2nd character: %c\n", c);

    printf("Enter another character: ");
    c = getch();
    printf("Read another 3rd character: %c\n", c);
    return 0;
}

