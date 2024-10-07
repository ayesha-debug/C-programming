 /*This program is to entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same
 * spacing. Use the same tab stops as for detab.When either a tab or a single blank would suffice to reach a tab stop, which should
 * be given preference?
 * if spaces are more than tabspaces then it replace spaces with tabspace
Name    : Sk.Ayesha
created :1 July,2024
Modified:1 July,2024 */

/** MACROS DEFINITIONS **/
#define TAB 4
#define MAX 500
/* MAIN PROGRAM */
/*
* main:content of main to entab spaces
*/
#include<stdio.h>
int main()
{
        int iCount=0,iInput=0,iIndex;
        int iSpaces =TAB;
        char sStr[MAX],cCharacter;
        /* To get input from user */
        while((cCharacter=getchar())!=EOF)
        {
                sStr[iInput++]=cCharacter;
        }
        /* Null terminating the string */
        sStr[iInput]='\0';

        /* Process the input string */
        for (iIndex = 0; sStr[iIndex]; iIndex++) 
	{
                if (sStr[iIndex] == ' ') 
		{
                        ++iCount;  /* Increment spaces count */
                        if (iCount == iSpaces) 
			{
                                printf("\\t");
                                /* Print tab for every 4 spaces */
                                iCount = 0;
                                /* Reset the count */
                        }
                } 
		else
	       	{
                        /* Print remaining spaces if count is less than 4 */
                        while (iCount > 0) 
			{
                                printf(" ");
                                iCount--;
                        }
                        printf("%c", sStr[iIndex]);
                        
			/*Print the non-space character */
                        if (sStr[iIndex] == '\n') 
			{
                                iCount = 0;
                                /* Reset count at the start of a new line */
                        }
                }
        }
}
