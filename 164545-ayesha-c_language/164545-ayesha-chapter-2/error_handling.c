// error_handling.c
#include <stdio.h>
#include "error_handling.h"

void handle_error(int error_code) {
    switch (error_code) {
        case ERROR_NONE:
            break;  // No error
        case ERROR_INVALID_INPUT:
            printf("Error: Invalid input entered.\n");
            break;
        case ERROR_OUT_OF_RANGE:
            printf("Error: Input out of range.\n");
            break;
        case ERROR_STEP_TOO_LARGE:
            printf("Error: Step size greater than upper bound.\n");
            break;
        case ZERO_DEVISION_ERROR:
            printf("Error: Zero division error.\n");
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
}

