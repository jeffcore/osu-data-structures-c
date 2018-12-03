/*
 * AVL.c
 *
 *  Created on: Aug 6, 2013
 *      Author: jeff
 */

/*
 File: avl.c
 Implementation of the binary search tree data structure.

 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "avl.h"

struct AVLnode {
	TYPE         val;
	struct AVLnode *left;
	struct AVLnode *right;
	int height;
};

struct AVLTree {
	struct AVLnode *root;
	int  cnt;
};


/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initAVLTree(struct AVLTree *tree)
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

struct AVLTree*  newAVLTree()
{
	struct AVLTree *tree = (struct AVLTree *)malloc(sizeof(struct AVLTree));
	assert(tree != 0);

	initAVLTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeAVL(struct AVLnode *node)
{
	if (node != 0) {
		_freeAVL(node->left);
		_freeAVL(node->right);
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
void clearAVLTree(struct AVLTree *tree)
{
	assert(tree != 0);

	_freeAVL(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}


/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteAVLTree(struct AVLTree *tree)
{
	assert(tree != 0);

	clearAVLTree(tree);
	free(tree);
}




/*

Main function for testing different fucntions of the Assignment#4.

*/


int containsAVLTree (struct AVLTree *tree, TYPE val)
{
	struct AVLnode *cur;
	cur = tree->root;

	while(cur != 0)
	{
		if(cur->val == val)
		{
			return 1;
		}
		else if(LT(cur->val, val))
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	return 0;

}


int _h(struct AVLnode * current)
{
	if (current == 0)
		return -1;
	return current->height;
}

void _setHeight (struct AVLnode * current)
{
	int lch = _h(current->left);
	int rch = _h(current->right);
	if (lch < rch) current->height = 1 + rch;
	else current->height = 1 + lch;
}


struct AVLnode * _rotateLeft (struct AVLnode * current)
{
	struct AVLnode *newTop = (struct AVLnode *) malloc(sizeof(struct AVLnode));
	newTop = current->right;
	current->right = newTop->left;
	newTop->left = current;

	_setHeight(newTop);
	_setHeight(current);

	return newTop;
}

struct AVLnode * _rotateRight (struct AVLnode * current)
{

	return current;
}
int _bf (struct AVLnode * current)
{
	return _h(current->right) - _h(current->left);
}


struct AVLnode *_balance (struct AVLnode * current)
{
	int cbf = _bf(current);
	if (cbf < -1)
	{
		if (_bf(current->left) > 0) // double rotation
			current->left = _rotateLeft(current->left);

		return _rotateRight(current); // single rotation
	}
	else if (cbf > 1)
	{
		if (_bf(current->right) < 0)
			current->right = _rotateRight(current->right);

		return _rotateLeft(current);
	}

	_setHeight(current);
	return current;
}


struct AVLnode * _AVLnodeAdd (struct AVLnode* current, TYPE newValue)
{
	struct AVLnode * newnode;
	if (current == 0)
	{
		newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
		assert(newnode != 0);
		newnode->val = newValue;
		newnode->left = newnode->right = 0;
		return newnode;  //why don’t we balance here ??
	}
	else if (LT(newValue, current->val))
	{
		current->left = _AVLnodeAdd(current->left, newValue);
	}
	else
	{
		current->right = _AVLnodeAdd(current->right, newValue);
	}

	return _balance(current); /* <-  NEW the call on balance */
}






void addAVLTree(struct AVLTree *tree, TYPE val)
{
	tree->root = _AVLnodeAdd(tree->root, val);
	tree->cnt++;
}


TYPE _leftMost(struct AVLnode *cur) {
	while(cur->left != 0)
	{
		cur = cur->left;
	}

	return cur->val;
}

struct AVLnode *_removeLeftMost(struct AVLnode *cur) {
	struct AVLnode *temp;
	if(cur->left != 0)
	{
		cur->left = _removeLeftMost(cur->left);
		return _balance(cur);
	}
	temp = cur->right;
	free(cur);
	return temp;
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
struct AVLnode *_removeNode(struct AVLnode *cur, TYPE val)
{
	assert(cur != 0);
	assert(val != 0);
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
	else if(LT(val,cur->val) == -1)
	{
		cur->left = _removeNode(cur->left, val);
	}
	else
	{
		cur->right = _removeNode(cur->right, val);
	}

	return  _balance(cur);

}



void removeAVLTree(struct AVLTree *tree, TYPE val)
{
	if (containsAVLTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}


int main(int argc, char *argv[]){

   //After implementing your code, please uncommnet the following calls to the test functions and test your code

	return 0;
}


