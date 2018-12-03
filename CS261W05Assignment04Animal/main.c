#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};


/*
Main function for testing different fucntions of the Assignment#4.

*/

int main(int argc, char *argv[]){

   //After implementing your code, please uncommnet the following calls to the test functions and test your code

	int gameState = 1;
	printf("Animal Guessing Game\n\n");
	
	printf("Think of an animal, then I will try to guess it.\n\n");

	FILE *f = fopen("data.txt", "r");
	assert(f != 0);

	struct BSTree *tree = newBSTree();


	tree->root = readATree(tree, f);
	fclose(f);

	while(gameState)
	{
		startGame(tree->root);
		beginTreeWrite(tree->root);

		printf("Would you like to play again?\n");
		if(!getInput())
		{
			printf("Goodbye\n");
			gameState = 0;
		}

	}
	deleteBSTree(tree);
	return 0;


}


