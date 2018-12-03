#ifndef __AVL_H
#define __AVL_H

/*
   File: avl.h
   Interface definition of the AVL tree data structure.
*/


#ifndef TYPE
#define TYPE int
#endif

struct AVLTree;
typedef int (*comparator)(void *left, void*right);
typedef void (*printer)(void *node);

/* Initialize binary search tree structure. */
void initAVLTree(struct AVLTree *tree);

/* Alocate and initialize search tree structure. */
struct AVLTree *newAVLTree();

/* Deallocate nodes in BST. */
void clearAVLTree(struct AVLTree *tree);

/* Deallocate nodes in BST and BST structure. */
void freeAVLTree(struct AVLTree *tree);

/*-- BST Bag interface --*/
int  isEmptyAVLTree(struct AVLTree *tree);
int     sizeAVLTree(struct AVLTree *tree);

void     addAVLTree(struct AVLTree *tree, void *val, comparator compare);
int containsAVLTree(struct AVLTree *tree, void *val, comparator compare);
void  removeAVLTree(struct AVLTree *tree, void *val, comparator compare);

/* Utility function to print a tree */
void printTree(struct AVLTree *tree, printer printVal);
void treeSort(TYPE data [], int n, comparator compare);
void treeSort2(TYPE data[], int n, comparator compare);
# endif
