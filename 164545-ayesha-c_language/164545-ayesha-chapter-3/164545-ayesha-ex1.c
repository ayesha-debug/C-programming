/*
 * This program implements a binary search that performs only one test
 * inside the loop, as opposed to two. It also includes a bubble sort
 * function to sort the array if it is not already sorted.
 * 
 * Author: Sk.Ayesha
 * Created: 4 July, 2024
 * Modified: 16 July, 2024
 */

/** Required header files */
#include <stdio.h>

/** Function prototypes */
int binsearch(int target, int array[], int size);
void bubblesort(int a[], int size);

/** Main program */
/** main: Calls the binary search function */
int main() 
{
    int range;

    // Prompt user for number of array elements
    printf("Enter number of array elements: ");
    scanf("%d", &range);

    int array[range]; 
    int target;       
    int kindex, value;

    // Enter array elements of given range
    printf("Enter an array:\n");
    for (kindex = 0; kindex < range; kindex++) 
    {
        scanf("%d", &array[kindex]);
    }

    // Prompt user for a number to search
    printf("Enter a number to search: ");
    scanf("%d", &target);

    // Perform binary search
    value = binsearch(target, array, range); 

    // Output the result
    if (value == -1) 
    {
        printf("Element %d not found in the array.\n", target);
    }
    else 
    {
        printf("Element %d found in the array at index %d.\n", target, value);
    }

    return 0; 
}

/* binsearch: find target in array[0] <= array[1] <= ... <= array[size-1] */
int binsearch(int target, int array[], int size) 
{
    int low = 0;
    int high = size - 1; 
    int mid;

    // Sort the array if not sorted
    for (int istart = 0; istart < size - 1; istart++) 
    {
        if (array[istart] > array[istart + 1]) 
	{
            printf("Array is not sorted, sorting the array...\n");
            bubblesort(array, size);
            // Print the sorted array
            for (int kindex = 0; kindex < size; kindex++)
                printf("%d ", array[kindex]);
            printf("\n");
            break; 
        }
    }

    // Perform binary search with only one test in the loop
    while (low <= high) 
    {
        mid = (low + high) / 2;

        if (target < array[mid]) 
	{
            high = mid - 1; 
        }
       	else if (target > array[mid]) 
	{
            low = mid + 1; 
        }
       	else 
	{
            return mid; 
        }
    }

    return -1; 
}

/* bubblesort: to sort an array using bubble sort algorithm */
void bubblesort(int a[], int size) {
    int temp;

    // Perform bubble sort
    for (int istart = 0; istart < size - 1; istart++) {
        for (int jstart = 0; jstart < size - 1 - istart; jstart++) {
            if (a[jstart] > a[jstart + 1]) {
                temp = a[jstart];
                a[jstart] = a[jstart + 1];
                a[jstart + 1] = temp;
            }
        }
    }
}

