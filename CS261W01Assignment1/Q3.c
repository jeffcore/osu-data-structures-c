/* CS261- Assignment 1 - Q.3*/
/* Name: Jeff Rix
 * Date: 6/29/13
 * Solution description:  Array sorting program
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	 /*I used selection sort because it was a small amount of element to be sorted*/
	int i, minPos;

	/*create identifier for sorted region, loops through array stopping before last element */
	for (i = 0; i < n - 1; i++) {
		/*Find the index of the minimum value*/
		minPos = i;
		/* compare element to sorted area  */
		for (int j = i + 1; j < n; j++) {
			if (number[j] < number[minPos]) {
				minPos = j;
			}
		}
		/*swap element after we have found it's new location*/
		swap(number, minPos, i);
	}

}




int main(){
    srand((unsigned)time(0));

	/*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *numArray = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    int i;
    for (i = 0; i < n; i++)
    {
    	numArray[i] =  (rand() % 1000) + 1;
    }

    /*Print the contents of the array.*/
    printf("Unsorted:\n");
    for (i = 0; i < n; i++)
	{
		printf("%d\n", numArray[i]);
	}
    
	/*Pass this array along with n to the sort() function of part a.*/
	sort(numArray, n);



    /*Print the contents of the array.*/    
	printf("Sorted:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", numArray[i]);
	}

    return 0;
}
