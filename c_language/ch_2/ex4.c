/*Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.*/
/*
 * Name 	:Sk.Ayesha
 * Date 	:10-07-2024
 * Modified Date:10-07-2024
 *
 */

/*Required header files*/
#include<stdio.h>

int if_it_same(char ch,const char s2[])
{
	int i;
	for(i = 0;s2[i] !='\0';i++)
	{
		if(ch == s2[i])
		{
			return 1;
		}
	}
        return 0;
	
}

void sqeeze(char s1[],const char s2[])
{
	int i ,j = 0;
	for(i = 0;s1[i] !='\0';i++)
	{
		if(! if_it_same(s1[i],s2))
		{
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}


int main()
{
	  char s1[100];
	  char s2[100];
	  int i ;

	  i = 0;
	  while((s1[i] = getchar()) != '\n' && i < 99)
	  {
		  i++;
	  }
	  s1[i] = '\0';
	  
	  i = 0;
	  while((s2[i] = getchar() )!= '\n' && i < 99)
	  {

		  i++;
	  }
	  s2[i] = '\0';

	  sqeeze(s1,s2);

	  printf("%s",s1);
}
         	  


