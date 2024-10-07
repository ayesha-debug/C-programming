//Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
/*
 * Name 	:Sk.Ayesha
 * Created	:22-06-2024
 * Modified Date:22-06-2024
 */

/*Header Files*/
#include<stdio.h>

/*
 * This program counts the number of characters, words, and lines in the input.
 * It reads input from the user and processes it until EOF is encountered.
 * The program correctly handles edge cases such as consecutive newlines and inputs
 * that do not end with a newline.
 */

int main()
{
    int input; 
    // Variable to store the character read from input
    int word_count = 0, line_count = 0, character_count = 0;
    int in_word = 0, prev_input = 0;
    int empty_input = 0;
    // Flag to check if any input was provided

    // Loop to read characters from input until EOF
    while ((input = getchar()) != EOF) 
    {
        // Increment character count for all characters except newline, space, and tab
        if (input != ' ' && input != '\n' && input != '\t') 
	{
            character_count++;
            empty_input = 1; 
	    // Set flag if input is non-empty
        }

        // Increment line count for non-consecutive newlines
        if (input == '\n') 
	{
            if (empty_input) 
	    {
                line_count++;
                empty_input = 0;
	       	// Reset flag for next potential line
            }
        }

        // Word counting logic
        if (input == ' ' || input == '\t' || input == '\n') 
	{
            in_word = 0;
        } 
	else if (!in_word) 
	{
            in_word = 1;
            word_count++;
        }

        prev_input = input;  
	// Update previous character
    }

    // If the input was non-empty and the last character was not a newline, increment line count
    if (character_count > 0 && prev_input != '\n') 
    {
        line_count++;
    }

    // Print the counts of characters, lines, and words
    printf("\nCharacter count: %d\nLine count: %d\nWord count: %d\n", character_count, line_count, word_count);

    return 0;
}

