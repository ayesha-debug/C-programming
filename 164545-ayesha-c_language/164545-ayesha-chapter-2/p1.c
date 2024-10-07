/*
 * Name         : Sk.Ayesha
 * Date         : 10-07-2024
 * Modified Date: 10-07-2024
 */

/* Required Header Files */
#include <stdio.h>
#include <string.h>   // For strcmp function
#include "error_handling.h"  // Custom error handling header file

/* Required Function Prototypes */
int htoi(const char s[]);

/* Hexadecimal to Integer Conversion Function */
/*
 * Function: htoi
 * ----------------------------
 *   Converts a string of hexadecimal digits (including an optional 0x or 0X)
 *   into its equivalent integer value.
 *
 *   s: string containing hexadecimal digits
 *
 *   returns: integer equivalent of the hexadecimal string, or -1 if invalid input
 */
int htoi(const char s[]) {
    int inner = 0;  // Index for iterating through the string
    int buffer = 0; // Variable to store the converted integer value

    // Skip optional "0x" or "0X" prefix
    if (s[inner] == '0' && (s[inner+1] == 'x' || s[inner+1] == 'X')) {
        inner += 2;  // Move the index past the prefix
    }

    // Loop through each character in the string
    while (s[inner] != '\0') {
        if (s[inner] >= '0' && s[inner] <= '9') {
            // Convert digit character to its integer value
            buffer = 16 * buffer + (s[inner] - '0');
        } else if (s[inner] >= 'a' && s[inner] <= 'f') {
            // Convert lowercase hex letter to its integer value
            buffer = 16 * buffer + (s[inner] - 'a' + 10);
        } else if (s[inner] >= 'A' && s[inner] <= 'F') {
            // Convert uppercase hex letter to its integer value
            buffer = 16 * buffer + (s[inner] - 'A' + 10);
        } else {
            // Invalid character encountered
            return -1;
        }
        inner++;  // Move to the next character
    }
    return buffer;  // Return the converted integer value
}

int main() {
    int output;  // Variable to store the output of the conversion
    char hexa_dec[100];  // Buffer to store the user's input string
    char response[4];    // Buffer to store the user's response for repeating the task

    do {
        // Prompt user for input
        printf("Enter a hexadecimal string (e.g., 0x2af): ");
        if (fgets(hexa_dec, sizeof(hexa_dec), stdin) == NULL) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;  // Return a non-zero value to indicate an error
        }

        // Remove newline character if present
        size_t len = strlen(hexa_dec);
        if (len > 0 && hexa_dec[len-1] == '\n') {
            hexa_dec[len-1] = '\0';
        }

        // Convert the hexadecimal string to an integer
        output = htoi(hexa_dec);

        // Check for conversion error
        if (output == -1) {
            handle_error(ERROR_INVALID_INPUT);
        } else {
            // Print the converted integer value
            printf("Decimal value: %d\n", output);
        }

        // Prompt the user if they want to perform the task again
        printf("Do you want to do the task again? (yes/no): ");
        if (fgets(response, sizeof(response), stdin) == NULL) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;  // Return a non-zero value to indicate an error
        }

        // Remove newline character if present
        len = strlen(response);
        if (len > 0 && response[len-1] == '\n') {
            response[len-1] = '\0';
        }

    } while (strcmp(response, "yes") == 0);

    return 0;  // Return 0 to indicate successful execution
}
/* End of the Program */

