/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "dynamicArray.h"
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

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)
{
	assert(val != 0);

	/*   check to see if current node is null then create and add new node  */
	if(cur == 0)
	{
		struct Node *newNode = malloc(sizeof(struct Node));
		assert(newNode != 0);
		newNode->val = val;
		newNode->left = newNode->right = 0;

		return newNode;
	}
	/* searching for location of new null, search left side of current tree or subtree  */
	if(compare(cur->val, val) == 1) //cur->val > val
	{
		/* if no null is found it always returns the same value as current left node */
		cur->left = _addNode(cur->left, val);
	}
	/*  searching for location of new null, search right side of current tree or subtree   */
	else
	{
		/* if no null is found it always returns the same value as current right node */
		cur->right = _addNode(cur->right, val);
	}

	return cur;
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
	assert(tree != 0);
	assert(val != 0);

	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	/*write this*/

	assert(tree != 0);
	assert(val != 0);

	struct Node *current = tree->root;

	/*start a root node and compare node value with val*/
	while(current != 0)
	{
		/*if value found return 1*/
		if(compare(current->val, val) == 0)
		{
			return 1;
		}
		/* if current value is greater go to left node */
		else if (compare(current->val, val) == 1)
		{
			current = current->left;
		}
		/* if current value is less than go to right node */
		else
		{
			current = current->right;
		}
	}
	return 0;

}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	assert(cur != 0);

	/* search for last left node*/
	while(cur->left != 0)
	{
		cur = cur->left;
	}

	return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	/*first time running it is given the matched nodes right node */
	assert(cur != 0);

	struct Node *returnNode = malloc(sizeof(struct Node));
	assert(returnNode != 0);

	/* If left node exists, perform recursion check next left node*/
	/*     this always returns the current node after running recursion */
	if(cur->left != 0)
	{
		cur->left = _removeLeftMost(cur->left);
		return cur;

	}
	/*	If the left node does not exist, just return the right node even if it is null */
	else
	{
		returnNode = cur->right;
		free(cur);
	}

	return returnNode;
}
/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree  ALREADY DONE IN THE STARTER FUNCTION
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	assert(cur != 0);
	assert(val != 0);
	//assert(val is in tree)

	/*current nodes value is equal to the value to be removed */
	if(compare(cur->val, val) == 0)
	{
		/*check if current nodes right node is null,  this means there is not tree to the right of this node, so we just replace with the left node */
		if(cur->right == 0)
		{
			return cur->left;
		}
		/* if there is a right node we start the left node methods */
		else
		{
			/* finds value of leftmost node and replaces current value */
			cur->val = _leftMost(cur->right);
			/* start recursion to rebuild tree and remove leftmost node */
			cur->right = _removeLeftMost(cur->right);
		}
	}
	else if(compare(val,cur->val) == -1)
	{
		cur->left = _removeNode(cur->left, val);
	}
	else
	{
		cur->right = _removeNode(cur->right, val);
	}

	return cur;

}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
	assert(tree != 0);
	assert(val != 0);
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used 
  in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);	 
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");
}

void printTree(struct BSTree *tree) {
	 if (tree == 0) return;	 
	 printNode(tree->root);	 
}
/*----------------------------------------------------------------------------*/

#endif


struct BSTIterator {
	struct DynArr   *stk;
	struct BSTree   *tree;
};

/*
 function to initialize the BSTIterator
 param: tree   the binary search tree
		itr		bst iterator
 pre:	tree is not null
		itr is not null
 post:	irt stack is created with 10 elements
 	 	irt tree pointed to passed parameter
 */
void BSTIteratorInit (struct BSTree *tree, struct BSTIterator *itr)
{
	assert(tree != 0);
	assert(itr != 0);

	itr->stk = createDynArr(10);
	itr->tree = tree;
}

/*
 pushes left side of tree onto stack
 param: cur   current node
		itr		bst iterator
 pre:	itr is not null
 post:	left side of tree in in the stack
 */
void _slideLeft(struct Node *cur, struct BSTIterator *itr)
{
	assert(itr != 0);

	while(cur != 0)
	{
		pushDynArr (itr->stk, cur);
		cur = cur->left;
	}
}

/*
 function that processes an inorder iteration on tree
 param: itr		bst iterator
 pre:	itr is not null
 returns:	returns 0 if tree is empty, returns 1 if not empty
 */
int BSTIteratorHasNext (struct BSTIterator * itr)
{
	assert(itr != 0);

	if(isEmptyDynArr(itr->stk))
	{
		_slideLeft(itr->tree->root, itr);
	}
	else
	{
		struct Node *cur = topDynArr(itr->stk);
		popDynArr(itr->stk);
		_slideLeft(cur->right, itr);

	}
	if (!isEmptyDynArr(itr->stk))
	{
		return 1;
	}

	return 0;

}

/*
 function that returns the current value of the node on the top of the stack
 param: itr		bst iterator
 pre:	itr is not null
 returns:	returns the current value of the node on the top of the stack
 */
TYPE BSTIteratorNext (struct BSTIterator *itr) {
	assert(itr != 0);

	struct Node *cur = topDynArr(itr->stk);

	return cur->val;
}

/*

Main function for testing different fucntions of the Assignment#4.

*/

int main(int argc, char *argv[]){	



	struct BSTree *tree	= newBSTree();
	printf("Adding 1,9,5,4,99,44,3,2 to BST");

	int data [] = {1,9,5,4,99,44,3,2};

	int i;
	for(i = 0; i < 8; i++)
	{
		struct data *myData = (struct data *) malloc(sizeof(struct data));
		myData->number = data[i];
		addBSTree(tree, myData);
	}

	struct BSTIterator *itr = malloc(sizeof(struct BSTIterator));
	BSTIteratorInit(tree, itr);

	printf("\nSorted Output \n");

	while(BSTIteratorHasNext(itr))
	{
		struct data *myData2 = BSTIteratorNext(itr);
		printf("%d ", myData2->number);
	}

	

	return 0;


}
