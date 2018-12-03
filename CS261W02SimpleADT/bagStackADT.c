/*
 * arrayBagStack.c
 *
 *  Created on: Jul 5, 2013
 *      Author: jeff
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include  "arrayBagStack.h"


int main(int argc, const char * argv[])
{
	printf("Begin Program...\n");
	printf("Testing Bag\n");
	struct arrayBagStack b;
	initArray(&b);
	printf("Add number 1 to bag.\n");
	addArray(&b, 1);
	printf("Add number 2 to bag.\n");
	addArray(&b, 2);
	printf("Add number 3 to bag.\n");
	addArray(&b, 3);
	printf("Does this bag contain a 2? (1 yes - 2 no):  %d\n", containsArray(&b, 2));
	printf("Does this bag contain a 4? (1 yes - 2 no):  %d\n", containsArray(&b, 5));
	printf("Size of Bag? (Should be 3):  %d\n", sizeArray(&b));
	printf("Remove number 2 from bag.\n");
	removeArray(&b, 2);
	printf("Size of Bag? (Should be 2):  %d\n", sizeArray(&b));
	printf("\n");
	printf("Testing Stack\n");

	struct arrayBagStack s;
	initArray(&s);

	printf("Add number 1 to stack.\n");
	pushArray(&s, 1);

	printf("Add number 2 to stack.\n");
	pushArray(&s, 2);

	printf("Add number 3 to stack.\n");
	pushArray(&s, 3);

	printf("Peek at Top of Stack. (should be 3): %d\n", topArray(&s));

	printf("Pop 3 off of the stack.\n");
	popArray(&s);
	printf("Peek at Top of Stack. (should be 2): %d\n", topArray(&s));

	printf("Pop 2 off of the stack.\n");
	popArray(&s);
	printf("Pop 1 off of the stack.\n");
	popArray(&s);
	printf("Is the stack empty? (1 yes - 2 no): %d\n", isEmptyArray(&b));


    return 0;
}

/* Bag Interface  Functions */

/*  Initalize the data array */
void initArray (struct arrayBagStack * b)
{
	int i;

	for(i = 0; i < 100; i++)
	{
		b->data[i] = 0;
	}

	b->count = 0;
}

/*  Add element to the end of the array */
void addArray (struct arrayBagStack * b, TYPE v)
{
	b->data[b->count] = v;
	b->count++;
}

/*  Checks of element is contained within the array
 *  returns 1 for yes, 2 for no
 */
int containsArray (struct arrayBagStack * b, TYPE v)
{
	assert(b->count > 0);

	int i;
	for (i = 0; i < b->count; i++)
	{
		if(EQ(v, b->data[i]))
		{
			return 1;
		}
	}
	return 0;
}

/* Removes element based on argument passed by user*/
void removeArray (struct arrayBagStack * b, TYPE v)
{
	assert(b->count > 0);

	int i;
	int j;
	for (i = 0; i < b->count; i++)
	{
		if (EQ(v, b->data[i]))
		{
			for (j = i; j < b->count; j++)
			{
				if(i == b->count - 1)
				{
					b->data[i] = '\0';
				}
				else
				{
					b->data[i] = b->data[i+1];
				}
			}
			b->count--;
			return;
		}
	}
}

/*  Returns the size of the array */
int sizeArray (struct arrayBagStack * b)
{
	return b->count;
}


/* Stack Interface  Functions */

/*  Add element to the stack */
void pushArray (struct arrayBagStack * b, TYPE v)
{
	b->data[b->count] = v;
	b->count++;
}

/*  Check to see the value of the element on the top of the stack */
TYPE topArray (struct arrayBagStack * b)
{
	assert(isEmptyArray(b) == 1);
	return b->data[b->count-1];
}

/*  Remove element on the top of the stack */
void popArray (struct arrayBagStack * b)
{
	assert(isEmptyArray(b) == 1);
	b->data[b->count-1] = '\0';
	b->count--;
}

/* Checks if array is empty
 * returns 1 for empty, 0 for not empty */
int isEmptyArray (struct arrayBagStack * b)
{
	if(b->count == 0)
	  return 0;
	else
	  return 1;
}
