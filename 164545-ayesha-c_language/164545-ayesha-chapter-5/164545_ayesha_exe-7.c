/*Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program? 
 * Name : Sk.Ayesha
 * Date : 29/8/2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
#include<ctype.h>
/** MACRO DEFINITIONS */
#define MAXLINES 100
#define MAXLEN 1000
/** FUNCTION PROTOTYPES */
int readlines(char *arr_ptr[],char *,int lines );
void writelines(char *arr_ptr[],int lines);
int get_line(char *,int);
 void swap(char *v[], int i, int j);
 void q_sort(char *lineptr[], int left, int right);
/** MAIN PROGRAM */
/** main: It uses buffer instead of dynamic memory allocation */
int main(){
	int line;
	char *lineptr[MAXLINES];
	char storage[MAXLEN];
	if((line=readlines(lineptr,storage,MAXLINES))>=0)
	{
		 q_sort(lineptr, 0, line-1);
		writelines(lineptr,line);
	}
	else {
		printf("Error: input too big to sort\n");
	}

	return 0;
}
/* End main() */
/* readlines : read input lines */
int readlines(char *lineptr[],char * storage,int maxlines ){

	int len, nlines=0;
	char *p=storage,line[MAXLEN];
	while((len=get_line(line,MAXLEN))>0)
		if(nlines>=maxlines)
			/* No space left in lineptr or storage */
			return -1;
		else{
			line[len-1]='\0';
			strcpy(p,line);
			lineptr[nlines++]=p;
			/* Move pointer to the next free position in storage */
			p+=len;
		}
	return nlines;


}
/* get_line: get a line from input */
int get_line(char *s,int lim)
{
	int c, i=0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n'){
		if(isalpha(c))
		s[i++] = c;
		}
	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;

}
/* writelines: write lines */
void writelines(char *arr_ptr[],int lines){
	int i;
	for(i=0;i<lines;i++)
		printf("%s \n",arr_ptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
 void q_sort(char *v[], int left, int right)
 {
 int i, last;
 void swap(char *v[], int i, int j);
 if (left >= right) /* do nothing if array contains */
 return; /* fewer than two elements */
 swap(v, left, (left + right)/2);
 last = left;
 for (i = left+1; i <= right; i++)
 if (strcmp(v[i], v[left]) < 0)
 swap(v, ++last, i);
 swap(v, left, last);
 q_sort(v, left, last-1);

 q_sort(v, last+1, right);
 }

 /* swap: interchange v[i] and v[j] */
 void swap(char *v[], int i, int j)
 {
 char *temp;
 temp = v[i];
 v[i] = v[j];
 v[j]=temp;

 }
/* End of swap */

