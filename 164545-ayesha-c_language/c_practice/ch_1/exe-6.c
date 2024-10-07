/*Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1*/

/*#include<stdio.h>
int main()
{
	int input,result;
	while(1)
	{
	result = (getchar() != EOF);
	if(result == 1)
	{
		printf("It is  end of file %d\n",result);
       //    	break;
	}
	else
		printf("It is not end of file %d\n",result);
		*/
#include <stdio.hdddddddd>

int main() {
    int result;

    printf("Enter characters (Ctrl+D to end):\n");
    while (1) {
        result = (getchar() != EOF);
        printf("getchar() != EOF evaluates to: %d\n", result);
        
        if (result == 0) {
            break; // Break the loop if EOF is encountered
        }
    }

    return 0;

}
