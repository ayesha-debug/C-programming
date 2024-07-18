#include <stdio.h>

// Function to calculate the length of a string
int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    // Sample array of strings
    char *lines[] = {
        "This is the first line.",
        "This is a longer line that should be the biggest.",
        "Short line.",
        "Another line that is longer than the previous one.",
        "The last line."
    };

    // Variables to track the biggest line and its length
    int max_length = 0;
    char *biggest_line = NULL;

    // Iterate through each line to find the biggest one
    for (int i = 0; i < sizeof(lines) / sizeof(lines[0]); i++) {
        // Calculate length of the current line
        int length = stringLength(lines[i]);

        // Compare current line length with max_length
        if (length > max_length) {
            max_length = length;
            biggest_line = lines[i];
        }
    }

    // Print the biggest line
    if (biggest_line != NULL) {
        printf("Biggest line: %s\n", biggest_line);
    }

    return 0;
}


