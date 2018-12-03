/*
 * AVL.h
 *
 *  Created on: Aug 6, 2013
 *      Author: jeff
 */

#ifndef AVL_H_
#define AVL_H_


# ifndef TYPE
# define TYPE      int
# endif

#ifndef LT
#define LT(a, b) (a < b)
#endif

struct AVLTree;
typedef int (*comparator)(void *left, void *right);


/* Declared in the c source file to hide the structure members from the user. */

/* Initialize binary search tree structure. */
void initAVLTree(struct AVLTree *tree);

/* Alocate and initialize search tree structure. */
struct AVLTree *newBSTree();

/* Deallocate nodes in BST. */
void clearAVLTree(struct AVLTree *tree);

/* Deallocate nodes in BST and deallocate the BST structure. */
void deleteAVLTree(struct AVLTree *tree);




//void removeAVLTree(struct AVLTree *tree, TYPE val);


#endif /* AVL_H_ */
