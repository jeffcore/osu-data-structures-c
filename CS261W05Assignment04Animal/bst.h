/*
  File: bst.h
  Interface definition of the binary search tree data structure.
*/

#ifndef __BST_H
#define __BST_H

/* Defines the type to be stored in the data structure.  These macros
 * are for convenience to avoid having to search and replace/dup code
 * when you want to build a structure of doubles as opposed to ints
 * for example.
 */

# ifndef TYPE
# define TYPE      void*
# endif


struct BSTree;
struct Node;
/* Declared in the c source file to hide the structure members from the user. */

/* Initialize binary search tree structure. */
void initBSTree(struct BSTree *tree);

/* Alocate and initialize search tree structure. */
struct BSTree *newBSTree();

/* Deallocate nodes in BST. */
void clearBSTree(struct BSTree *tree);

/* Deallocate nodes in BST and deallocate the BST structure. */
void deleteBSTree(struct BSTree *tree);

/*-- BST Bag interface --*/
int  isEmptyBSTree(struct BSTree *tree);
int     sizeBSTree(struct BSTree *tree);

char * newStr (char * charBuffer);
void beginTreeWrite(struct Node *cur);
struct Node *readATree (struct BSTree *tree, FILE * f);
void flush( void );
int getInput();
void addNewQuestion(struct Node *cur);
void startGame (struct Node *cur);
void startGame2 (struct Node *cur); /*  did not use */

# endif
