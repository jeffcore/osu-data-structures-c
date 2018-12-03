#include<stdio.h>
#include<stdlib.h>
#include "avl.h"
#include "structs.h"

/* prototype for compare and printVal which are both in compare.c*/
int compare(void *left, void *right);


/* Example main file to begin exercising your tree */


int main(int argc, char *argv[])
{	

	 printf("Adding 1,9,5,4,99,44,3,2 to tree");

	TYPE data [] = {1,9,5,4,99,44,3,2};
	
	treeSort2(data, 8, compare);

    int i;

	//treeSort(data, 8, compare);

	printf("\nSorted Output \n");

	for (i = 0; i < 8; i++)
	{
		printf("%d ", data[i]);
	}




	return 1;
}


