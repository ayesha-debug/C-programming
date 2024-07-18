//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.

#include<stdio.h>
#define total_char 256
int main()
{
	char ch;
	int arr[total_char];
	while((ch = getchar()) != EOF)
	{


