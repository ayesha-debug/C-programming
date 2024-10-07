#include <stdio.h>

int main() {
    int input;  // Use int to handle EOF properly
    int word_count = 0, line_count = 0, character_count = 0;
    int in_word = 0, prev_input = 0;
    int is_input_non_empty = 0; // Flag to check if any input was provided

    while ((input = getchar()) != EOF) {
        if (input != ' ' && input != '\t' && input != '\n') {
            character_count++;
            is_input_non_empty = 1; // Set flag if input is non-empty
        }

        // Increment line count for non-consecutive newlines with actual content
        if (input == '\n') {
            if (is_input_non_empty) {
                line_count++;
                is_input_non_empty = 0; // Reset flag for next potential line
            }
        }

        // Word counting logic
        if (input == ' ' || input == '\t' || input == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }

        prev_input = input;  // Update previous character
    }

    // If the input was non-empty and the last character was not a newline, increment line count
    if (character_count > 0 && prev_input != '\n') {
        line_count++;
    }

    printf("\nCharacter count: %d\nLine count: %d\nWord count: %d\n", character_count, line_count, word_count);

    return 0;
}

