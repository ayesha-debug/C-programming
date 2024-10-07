#include <stdio.h>
#define max 100

void user_input(char *input_str, int Max);

int main()
{
    char main_str[max];
    char sub_str[max];
    user_input(main_str, max);
    printf("Main string is %s\n", main_str);
    return 0;
}

void user_input(char input_str[], int Max)
{
    char input;
    int index = 0;

    for (int upper = Max; upper > 0 && ((input = getchar()) != EOF && input != '\n'); upper--)
    {
        input_str[index++] = input;
    }
    input_str[index] = '\0'; // Corrected to null terminate the string
}

