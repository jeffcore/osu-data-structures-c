/* CS261- Assignment 1 - Q.4*/
/* Name: Jeff Rix
 * Date: 6/29/13
 * Solution description:  struct sorting program
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void swap(struct student* students, int i, int j) {
	struct student tempStudent = students[i];
	students[i] = students[j];
	students[j] = tempStudent;
}


void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
	 /*I used selection sort because it was a small amount of element to be sorted*/
	int i, minPos;
	/*create identifier for sorted region, loops through array stopping before last element */
	for (i = 0; i < n - 1; i++) {
		// Find the index of the minimum value
		minPos = i;
		/* compare element to sorted area  */
		for (int j = i + 1; j < n; j++) {
			if (students[j].score < students[minPos].score) {
				minPos = j;
			}
		}
		/*swap element after we have found it's new location*/
		swap(students, minPos, i);
	}

}

int main(){

	srand((unsigned)time(0));

	/*Declare an integer i to be used in the for loops iteration.*/
	int i;

    /*Declare an integer n and assign it a value.*/
    int n = 20;

    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    for (i = 0; i < n; i++)
   	{
    	students[i].id = (rand() % 10) + 1;
    	students[i].score = (rand() % 100) + 1;
   	}
    
    /*Print the contents of the array of n students.*/
    printf("Unsorted:\n");

    for (i = 0; i < n; i++)
   	{
    	printf("ID%d - Score %d\n", students[i].id, students[i].score);
   	}

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("Sorted:\n");

    for (i = 0; i < n; i++)
	{
    	printf("ID%d - Score %d\n", students[i].id, students[i].score);
	}

    return 0;
}
