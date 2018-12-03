/* CS261- Assignment 1 - Q.1*/
/* Name: Jeff Rix
 * Date: 6/29/13
 * Solution description:  Struct examples
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	 struct student *s = malloc(10 * sizeof(struct student));

	 /*assert that the pointer is not null*/
	 assert(s != 0);

     /*return the pointer*/
	 return s;
}

void generate(struct student* students){
	 srand((unsigned)time(0));

	/*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int i;
	 for (i = 0; i < 10; i++)
	 {
		 students[i].id = (rand() % 10) + 1;
		 students[i].score = (rand() % 100) + 1;
	 }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	 int i;
	 for (i = 0; i < 10; i++)
	 {
		 printf("ID%d - Score %d\n", students[i].id, students[i].score);
	 }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

	struct student s;
	double average = 0;    /* variable to save the average score  */
	int i;


	/* find the student with the minimum score  */
	for (i = 0; i < 10; i++)
	{

		if(i == 0)
		{
			s = students[i];
		}
		else
		{
			if (students[i].score < s.score)
			{
				s = students[i];
			}
		}
	}

	printf("The minimum student score is: %d\n", s.score);

	/* find the student with the maximum score  */

	for (i = 0; i < 10; i++)
	{

		if(i == 0)
		{
			s = students[i];
		}
		else
		{
			if (students[i].score > s.score)
			{
				s = students[i];
			}
		}
	}

	printf("The max student score is: %d\n", s.score);

	/* find the average student score  */

	/* total up the scores  */

	for (i = 0; i < 10; i++)
	{
		average += students[i].score;
	}

	/* calculate the averages  */
	average = average/10;


	printf("The average student score is: %.2f\n", average);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if(stud != NULL)
	{
		printf("the students are free");
		free(stud);
	}
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
