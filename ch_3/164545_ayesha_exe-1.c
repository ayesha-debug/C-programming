/*Example-1:Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none*/

/*Author		:Sk.Ayesha
 * Created		:12=07-2024
 * Modified		:12-07-2024
 */

/*Required Header Files*/
#include<stdio.h>

int strindex(char str[],char search)
{
	int upper;
	for(right = 0;str[right] != '\0';right++);
	for(left = right ;str[left] != 0;left--)
	{
		if(str[upper] == search)
		{
			return str[upper];
		}
	}
	return -1;
}

int main()
{
	char s[20];
	char element;
	int index;

	printf("Enter the string\n");
	scanf("%[^\n]",s);

	printf("Enter the element to search\n");
	scanf(" %c",&element);
        
	index = strindex(s,element);

	if(index != -1)
	{
		printf("element is found in %d index \n",index);
	}
	else
		printf("element is not found in the string\n");

}
