/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"

/*private functions */
struct Node *_addNode(struct Node *cur, TYPE val);
TYPE _leftMost(struct Node *cur);
struct Node *_removeNode(struct Node *cur, TYPE val);
void _printNodes(struct Node *cur);

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
	return (tree->cnt == 0);
}

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree)
{
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
	struct Node *newNode;

	/*   check to see if current node is null then create and add new node  */
	if(cur == 0)
	{
		newNode = malloc(sizeof(struct Node));
		assert(newNode != 0);
		newNode->val = val;
		newNode->left = newNode->right = 0;
		return newNode;
	}
	/* searching for location of new null, search left side of current tree or subtree  */
	if(val < cur->val)
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
	assert(tree != 0);


	struct Node *current = tree->root;


	while(current != 0)
	{
		if(current->val == val)
		{
			return 1;
		}
		else if (val < current->val)
		{
			current = current->left;
		}
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
	/*write this*/


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
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	assert(cur != 0);
	//assert(val != NULL);
	//assert(val is in tree)

	/*current nodes value is equal to the value to be removed */
	if(cur->val == val)
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
	else if(val < cur->val)
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
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}


void _printNodes(struct Node *cur)
{
	if (cur == 0)
	{
		return;
	}
	else
	{
		printf("Node: %d ", cur->val);

		if(cur->left != 0)
		{
			printf(" Left : %d ", cur->left->val);
		}
		else
		{
			printf(" Left :Null ");
		}
		if(cur->right != 0)
		{
			printf(" right : %d ", cur->right->val);
		}
		else
		{
			printf(" Left :Null ");
		}
		printf("\n");printf("\n");

		_printNodes(cur->left);

		_printNodes(cur->right);
	}
}

void printTree(struct BSTree *tree)
{
	_printNodes(tree->root);
}
int main(int argc, char *argv[]){	

   //After implementing your code, please uncommnet the following calls to the test functions and test your code 

   // testAddNode();
	
	struct BSTree *bst = newBSTree();
	printf("Add 25,55,45,2,6,5,1,21 to tree\n");
	addBSTree(bst, 25);
	addBSTree(bst, 55);
	addBSTree(bst, 45);
	addBSTree(bst, 2);
	addBSTree(bst, 6);
	addBSTree(bst, 5);
	addBSTree(bst, 1);
	addBSTree(bst, 21);

	printTree(bst);

	printf("Remove 2\n");

	removeBSTree(bst,6 );

	printTree(bst);
	printf("fin\n");
    deleteBSTree(bst);
	return 0;
}
