/*
 * iteratorDynamicArray.c
 *
 *  Created on: Jul 16, 2013
 *      Author: jeff
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# ifndef TYPE
# define TYPE int
# endif


/* Dynamic Array Implementation   */

struct DynArr
{
    TYPE *data;
    int size;
    int capacity;
    /* pointer to the data array */
    /* Number of elements in the array */ /* capacity ofthe array */
};

void initDynArr(struct DynArr *v, int capacity)
{
    v->data = malloc(sizeof(TYPE) * capacity);
    assert(v->data != '\0');
    v->size = 0;
    v->capacity = capacity;
}

void freeDynArr(struct DynArr *v)
{
    if(v->data != 0)
    {
        free(v->data); /* free the space on the heap */
        v->data = 0;   /* make it point to null */
    }
    v->size = 0;
    v->capacity = 0;
}

int sizeDynArr( struct DynArr *v)
{
    return v->size;
}

void _setCapacityDynArr(struct DynArr *v, int newCap)
{
    int i;
    TYPE *dataTemp = malloc(sizeof(TYPE)*newCap);

    assert(dataTemp != 0);

    for(i = 0;i < newCap; i++)
    {
        dataTemp[i] = v->data[i];
    }

    free(v->data);
    v->data = dataTemp;
    v->capacity = newCap;
}

void addDynArr(struct DynArr *v, TYPE value) {
    /* Check to see if a resize is necessary */
    if(v->size >= v->capacity)
        _setCapacityDynArr(v, 2 * v->capacity);

    v->data[v->size] = value;

    v->size++;
}

TYPE getDynArr (struct DynArr * da, int position)
{
    assert(position >= 0 && position < da->size);

    return da->data[position];
}

void putDynArr(struct DynArr * da, int position, TYPE value) {

    assert(position >= 0 && position < da->size);

    da->data[position] = value;

}

void swapDynArr (struct DynArr * da, int i, int j)
{
    assert(i >= 0 && i < da->size);
    assert(j >= 0 && j < da->size);

    int temp = da->data[j];
    da->data[j] = da->data[i];
    da->data[i] = temp;
}

void removeAtDynArr (struct DynArr * da, int index) {
    assert(index >= 0 && index < da->size);

    int i;

    for (i = index; i < da->size; i++)
    {
        if(i == da->size - 1)
        {
            da->data[i] = '\0';
        }
        else
        {
            da->data[i] = da->data[i+1];
        }
    }
    da->size--;
}



struct dynArrayIterator
{
	struct DynArr * da;
	int currentIndex;
};

void dynArrayIteratorInit (struct DynArr *da, struct dynArrayIterator *itr)
{
	itr->da = da;
	itr->currentIndex = 0;
}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr)
{

	if(itr->currentIndex < itr->da->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr)
{
	return itr->da->data[itr->currentIndex++];
}

void dynArrayIteratorRemove (struct dynArrayIterator *itr)
{
	removeAtDynArr(itr->da, itr->currentIndex--);
}

int main(int argc, const char * argv[])
{
	printf("Begin Program\n");
	printf("\n");
	printf("Testing Dynamic Array\n");
	printf("Create Struct\n");
	int i;
	TYPE current;
	struct DynArr *da = malloc(sizeof(struct DynArr));
	struct dynArrayIterator *itr = malloc(sizeof(struct dynArrayIterator));
	initDynArr(da, 5);
	dynArrayIteratorInit(da, itr);

	printf("Create Array\n");
	addDynArr(da, 1);
	addDynArr(da, 2);
	addDynArr(da, 3);
	addDynArr(da, 4);
	addDynArr(da, 5);

	printf("\nView all elements in array\n");

	for(i = 0; i < da->size; i++)
	{
		printf("%d, ", da->data[i]) ;
	}
	printf("\nremove 3\n");

	while(dynArrayIteratorHasNext(itr))
	{
		current = dynArrayIteratorNext(itr);

		if(current < 3)
		{
			dynArrayIteratorRemove(itr);
		}
	}
	printf("View all elements in array\n");

	for(i = 0; i < da->size; i++)
	{
		printf("%d, ", da->data[i]) ;
	}



}
