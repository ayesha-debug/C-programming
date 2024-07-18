/*
 * Name         : Sk. Ayesha
 * Created      : 22-06-2024
 * Modified Date: 22-06-2024
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 20 // Maximum word length to consider

int main() {
    char current_char;
    int word_length = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0}; // Array to store word lengths

    // Count word lengths
    while ((current_char = getchar()) != EOF) {
        if (current_char == ' ' || current_char == '\t' || current_char == '\n') {
            // End of word
            if (word_length > 0) {
                if (word_length <= MAX_WORD_LENGTH) {
                    ++word_lengths[word_length];
                } else {
                    ++word_lengths[MAX_WORD_LENGTH]; // Count for words longer than MAX_WORD_LENGTH
                }
                word_length = 0; // Reset word length counter
            }
        } else {
            // Inside a word
            ++word_length;
        }
    }

    // Print vertical histogram
    printf("Word Lengths Histogram:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("%2d | ", i);
        for (int j = 0; j < word_lengths[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
    if (word_lengths[MAX_WORD_LENGTH] > 0) {
        printf(">%d | ", MAX_WORD_LENGTH);
        for (int j = 0; j < word_lengths[MAX_WORD_LENGTH]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}

