/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"
#include <string.h>


struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
	assert(tree != 0);

	tree->cnt  = 0;
	tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
	assert(tree != 0);

	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
	assert(tree != 0);

	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree)
{
	assert(tree != 0);

	return (tree->cnt == 0);
}

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree)
{
	assert(tree != 0);

	return tree->cnt;
}


/*--------------------------------------------------------------------
 *
 * Beginning of Animal Game Code
 * -------------------------------------------------------------------
 */



/*----------------------------------------------------------------------------*/
/*
 function to copy buffer to char array pointer
 param: char * buffer
 post: p is a pointer to string

 */
char * newStr (char * charBuffer)
{
   char * p = (char *) malloc(1 + strlen(charBuffer));
   strcpy (p, charBuffer);
   return p;
}



/*----------------------------------------------------------------------------*/
/*
 recursive helper function write to file data.txt

 param:  cur	the current root node
		 f		opened file writing

 */
void  _writeATree (struct Node *cur, FILE * f)
{
	char buffer[80];
	struct data *myData = (struct data *)cur->val;
	assert(myData != 0);

	/*end recursion of if it is an leaf node or answer */
	if (cur->left == 0 && cur->right == 0)
	{
		char prepend[80] = "A";
		strcat(prepend, myData->name);
		strcpy(buffer, prepend); /* put some text into the buffer area */
		fputs(buffer, f);
	}
	else
	{
		/*question node: continue recursion starting with left  then right node */

		char prepend[80] = "Q";
		strcat(prepend, myData->name);
		strcpy(buffer, prepend); /* put some text into the buffer area */

		fputs(buffer, f);

		_writeATree(cur->left, f);
		_writeATree(cur->right, f);
	}
}

/*----------------------------------------------------------------------------*/
/*
  starter function used to write tree to file data.txt
  param:  cur	the current root node

 */
void beginTreeWrite(struct Node *cur)
{
	FILE * f;
	f = fopen("data.txt", "w");
	assert(f != 0);
	_writeATree(cur, f);
	fclose(f);
}

/*----------------------------------------------------------------------------*/
/*
 recursive function used to read tree from file data.txt

 param:  tree	used to increment count of tree
		 f		opened file to read
 return:  node	used to build tree recursively

 */
struct Node *readATree (struct BSTree *tree, FILE * f)
{
	char c, buffer[100];
	struct Node *newNode = malloc(sizeof(struct Node));
	assert(newNode != 0);
	struct data *myData = (struct data *) malloc(sizeof(struct data));
	assert(myData != 0);

	/*double check to see if file is done this will only trigger if data.txt if formated incorrectly*/
	if(!feof(f))
	{
	  c = fgetc(f);
	  /*create answer node end recursion */
	  if (c == 'A')
	  {
		 fgets(buffer, 100, f);

		 myData->name = newStr(buffer);
		 newNode->val = myData;
		 newNode->left = newNode->right = 0;

		 tree->cnt++;
		 return newNode;

	  }
	  /*create question node continue recursion */
	  else
	  {
		 fgets(buffer, 100, f);

		 myData->name = newStr(buffer);

		 newNode->val = myData;
		 newNode->left = readATree(tree, f);
		 newNode->right = readATree(tree, f);

	  }
	}
	tree->cnt++;

	return newNode;
}


/*----------------------------------------------------------------------------*/
/*
 used to flush out stdin stream

 */
void flush( void ) {
    while ( getchar() != '\n' )
        ;
}


/*----------------------------------------------------------------------------*/
/*
  function used to get user yes no input

  return:  int 1 yes 0 false

 */
int getInput()
{
	char input;

	printf(" type Y or N: ");

	fflush(stdout);
	scanf("%c", &input);
	flush();

	if(input == 'Y' ||input == 'y' )
	{
		input = 1;
	}
	else
	{
		input = 0;
	}
	return input;
}


/*----------------------------------------------------------------------------*/
/*
 function used to create a new question if program guesses incorrectly
 param:  Node	current node were the computer guessed incorrectly

 */
void addNewQuestion(struct Node *cur)
{
	char buffer[100];
	char buffer2[100];
	/*create new right and left nodes*/
	struct Node *noRightNode = malloc(sizeof(struct Node));
	assert(noRightNode != 0);
	struct Node *yesLeftNode = malloc(sizeof(struct Node));
	assert(yesLeftNode != 0);
	/*create data nodes*/
	struct data *question = (struct data *) malloc(sizeof(struct data));
	assert(question != 0);
	struct data *yesAnswer = (struct data *) malloc(sizeof(struct data));
	assert(yesAnswer != 0);
	struct data *noAnswer = (struct data *) cur->val;
	assert(noAnswer != 0);

	/*set values of right no node*/
	noRightNode->val = noAnswer;
	noRightNode->left = noRightNode->right = 0;

	/*get answer (animal) from use */
	printf("What was your animal?");
	fflush(stdout);
	fgets(buffer, 100, stdin );

	/*set values of left yes node*/
	yesAnswer->name = newStr(buffer);
	yesLeftNode->val = yesAnswer;
	yesLeftNode->left = yesLeftNode->right = 0;

	/*get question from user*/
	printf("Give me a question that would differentiate it from a %s", noAnswer->name );
	fflush(stdout);
	fgets( buffer2, 100, stdin );

	/*set values of question node and set yes and no nodes*/
	question->name = newStr(buffer2);
	cur->val = question;
	cur->right = noRightNode;
	cur->left = yesLeftNode;

}


/*----------------------------------------------------------------------------*/
/*
resursive function used to ask questions and follow tree

 param:  Node	current node of the tree

 */
void startGame (struct Node *cur)
{
	int input;

	struct data *newData = (struct data *)cur->val;

	if (cur->left == 0 && cur->right == 0)
	{
		printf("Are you thinking of a %s", newData->name);
		input = getInput();

		if(input)
		{
			printf("I guessed right\n\n");
		}
		else
		{
			printf("I guessed wrong\n");
			printf("Would you like to add a question?\n");
			if(getInput())
			{
				addNewQuestion(cur);
			}
		}
	}
	else
	{
		printf("%s", newData->name);
		input = getInput();

		if(input)
		{
			startGame(cur->left);
		}
		else
		{
			startGame(cur->right);
		}
	}
}

/*iterative version of startGame function ended up not using*/
void startGame2 (struct Node *cur)
{
	int input;
	int gameState = 1;
	while (gameState)
	{
		struct data *newData = (struct data *)cur->val;
		if (cur->left == 0 && cur->right == 0)
		{
			printf("Is it a %s\n", newData->name);
			input = getInput();

			if(input)
			{
				printf("I guessed right\n");
				gameState = 0;
			}
			else
			{
				printf("I guessed wrong\n");
				printf("Would you like to add a question?\n");
				if(getInput())
				{
					addNewQuestion(cur);
				}
				else
				{
					gameState = 0;

				}
			}
		}
		else
		{
			printf("%s", newData->name);
			input = getInput();

			if(input)
			{
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}
	}

}

/*

Main function for testing different fucntions of the Assignment#4.

*/

