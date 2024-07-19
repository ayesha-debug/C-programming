/*Example: 5 Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)*/

/*
 * Name		:Sk.Ayesha
 * Date		:10-07-2024
 * Modified Date:10-07-2024
 *
 */

/*Required header files*/
#include<stdio.h>

/*This function is for comparing the string1 characters with string2
 *Outer Loop:The outer loop iterates over each character in str1 using the pointer p1.
 *Inner Loop:The inner loop iterates over each character in str2 using the pointer p2.
 *Inside the inner loop, it compares the character pointed to by p1 with the character pointed to by p2.
 *If a matching character is found, the function returns the index of the character in str1.
 *If no matching character is found after all comparisons, the function returns -1.
*/

int any(const char *str1, const char *str2)
{
	const char *p1,*p2;
	for(p1 = str1; *p1 != '\0'; p1++)
	{
		for(p2 = str2; *p2 != '\0'; p2++)
		{
			if(*p1 == *p2)
			{
				return p1 - str1;
			}
		}
	}
	return -1;

}
/*End of the Function*/

int main()
{
	const char *str1 = "ayesha";
	const char *str2 = "fh";
	int index;
	index = any(str1, str2);
	if(index != -1)
	{
		printf("matching character is found in %d index\n",index);
	}
	else
		printf("character is not matched\n");
}

/*End of the main function*/
