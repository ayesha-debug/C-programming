/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include<stdio.h>
int main()
{
        char ch;
        int word_count = 0;
        while((ch = getchar()) != EOF)
        {
                if((ch == ' ') || (ch == '\t') || (ch == '\n'))
                {
                        printf(" ");
                }
                else
                {
                        printf("*");
                }
        }
//      printf("\n word_count is %d\n",word_count);
 }
