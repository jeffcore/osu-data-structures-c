/*
 * QueueADT.c
 *
 *  Created on: Jul 10, 2013
 *      Author: JeffR
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# ifndef TYPE
# define TYPE int
# endif

# ifndef EQ
# define EQ(a, b) (a == b)
# endif



struct deque
{
	TYPE * data;
	int capacity;
	int size;
	int beg;
};

void dequeInit (struct deque *d, int initCapacity)
{
	d->data = (TYPE *) malloc(initCapacity * sizeof(TYPE));
	assert(d->data != 0);
	d->size = d->beg = 0;
	d->capacity = initCapacity;
}

void _dequeSetCapacity (struct deque *v, int newCap)
{
	int i;
	/* Create a new underlying array*/
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);
	/* copy elements to it */
	int j = v->beg;
	//copy through previous array from element 0 to size of contents
	for(i = 0; i <  v->size; i++)
	{
		//copy previous array beginning position into new data at index 0
		newData[i] = v->data[j];

		//increment j by one
		j = j + 1;

		//if you reach the end of the previous array reset j to loop around
		if(j >= v->capacity)
			j = 0;
	}
	/* Delete the oldunderlying array*/
	free(v->data);
	/* update capacity and size and data*/
	v->data = newData;
	v->capacity = newCap;
	v->beg = 0;
}

void dequeFree (struct deque *d)
{
	free(d->data);
	d->size = 0;
	d->capacity = 0;
}


int dequeSize (struct deque *d)
{
	return d->size;
}

void _dequeDoubleCapacity (struct deque *d)
{
	_dequeSetCapacity(d, 2 * d->capacity);
}

void dequeAddFront (struct deque *d, TYPE newValue) {
	int index;
	if (d->size >= d->capacity)
	{
		_dequeSetCapacity(d, 2*d->capacity);
	}
	index = d->beg - 1;

	if(index < 0)
	{
		index = d->capacity - 1;
	}

	d->data[index] = newValue;
    d->beg  = index;
	d->size++;
}

void dequeAddBack (struct deque *d, TYPE newValue)
{
	int index;
	if (d->size >= d->capacity)
	{
		_dequeSetCapacity(d, 2* d->capacity);
	}

	index = d->beg + d->size; //compute index
	if (index >= d->capacity) //wrap
	{
		index -= d->capacity;
	}

	d->data[index] = newValue;
	d->size++;
}

TYPE dequeFront (struct deque *d)
{
	return d->data[d->beg];
}

TYPE dequeBack (struct deque *d)
{
	int index = d->beg + d->size - 1;
	if (index > d->capacity)
	{
		index -= d->capacity;
	}

	return d->data[index];
}

void dequeRemoveFront (struct deque *d)
{
	assert(d->size > 0);
	d->size--;
	if (d->beg + 1 == d->size)
	{
		d->beg = 0;
	}
	{
		d->beg++;
	}
}

void dequeRemoveBack (struct deque *d)
{
	assert(d->size > 0);
	d->size--;
}



int main() {
	 struct deque *d = malloc(sizeof(struct deque));
	 dequeInit(d, 10);

	 printf("size of deque (0): %d\n", dequeSize(d));
	 printf("Add front (0,9)\n");
	 dequeAddFront(d, 0);
	 dequeAddFront(d, 9);
	 printf("size of deque (2): %d\n", dequeSize(d));


	 printf("Add end (1,2,3)\n");
	 dequeAddBack(d, 1);
	 dequeAddBack(d, 2);
	 dequeAddBack(d, 3);
	 printf("size of deque (5): %d\n", dequeSize(d));





	 printf("Add front (8,7,6)\n");
	 dequeAddFront(d, 8);
	 dequeAddFront(d, 7);
	 dequeAddFront(d, 6);
	 printf("Add end (4,5)\n");
	 dequeAddBack(d, 4);
	 dequeAddBack(d, 5);

	 printf("size of deque (10): %d\n", dequeSize(d));

	 printf("Add end\n");
	 dequeAddBack(d, 10);
	 printf("size of deque (11): %d\n", dequeSize(d));


	 printf("deque front (6) : %d \n", dequeFront(d));
	 printf("deque back (10): %d \n", dequeBack(d));
	 printf("remove front\n");

	 dequeRemoveFront(d);

	 printf("size of deque (10): %d\n", dequeSize(d));
	 printf("remove back\n");

	 dequeRemoveBack(d);

	 printf("size of deque (9): %d\n", dequeSize(d));

	 return 0;
}
