/*
 * Name         : Sk.Ayesha
 * Date         : 10-07-2024
 * Modified Date: 10-07-2024
 *
 * Description: This program implements the function `any(s1, s2)`,
 * which returns the first index in string `s1` where any character
 * from string `s2` occurs, or -1 if no such character exists.
 */

/* Required header files */
#include <stdio.h>

/*
 * Function: any
 * --------------------
 * Compares the characters of string `s1` with those in string `s2`.
 * 
 * Parameters:
 *   str1: A pointer to the first string to be searched.
 *   str2: A pointer to the second string containing characters to match.
 * 
 * Returns:
 *   The index of the first occurrence of any character from `s2` in `s1`.
 *   Returns -1 if no character from `s2` is found in `s1`.
 */
int any(const char *str1, const char *str2) {
    const char *p1, *p2;

    // Iterate through each character in str1
    for (p1 = str1; *p1 != '\0'; p1++) {
        // Iterate through each character in str2
        for (p2 = str2; *p2 != '\0'; p2++) {
            // Check for a match
            if (*p1 == *p2) {
                return p1 - str1;  // Return the index of the match
            }
        }
    }
    return -1;  // Return -1 if no match found
}

int main() {
    const char *str1 = "ayesha";  // The string to search
    const char *str2 = "fh";       // The characters to match
    int index;

    // Call the any function and store the result
    index = any(str1, str2);
    
    // Print the result based on the index
    if (index != -1) {
        printf("Matching character is found at index %d\n", index);
    } else {
        printf("No matching character found\n");
    }

    return 0;  // End of the main function
}

