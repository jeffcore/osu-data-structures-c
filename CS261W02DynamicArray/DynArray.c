/*
  DynArray.c
  Dynamic Array and Stack ADT Implementation
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
    assert(v->data !=  0);
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

void dynArrayAddAt (struct DynArr * da, int index, TYPE val) {
	int i;
	assert(da != 0);
	assert(da->size != 0);
	if(da->size == da->capacity)
	{
		_setCapacityDynArr(da, da->capacity * 2);
	}

	for(i = index; i < da->size; i++)
	{
		da->data[i+1] = da->data[i];
	}
	da->data[index] = val;
	da->size++;
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

/*Stack ADT Implementation */
int isEmptyDynArray (struct DynArr * da)
{
    if(da->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void pushDynArray (struct DynArr * da, TYPE value)
{
	addDynArr(da, value);
}

TYPE topDynArray (struct DynArr * da)
{
	assert(isEmptyDynArray(da) == 0);
	return getDynArr(da, sizeDynArr(da) - 1);
}

void popDynArray (struct DynArr * da)
{
	assert(isEmptyDynArray(da) == 0);
	removeAtDynArr(da, sizeDynArr(da) - 1);
}

int main(int argc, const char * argv[])
{
    int i;

    printf("Begin Program\n");
    printf("\n");
    printf("Testing Dynamic Array\n");
    printf("Create Struct\n");
    struct DynArr *da = malloc(sizeof(struct DynArr));

    printf("Create Array\n");
    initDynArr(da, 5);

    printf("Size of array - (Should be 0): %d\n", sizeDynArr(da));
    printf("Add element 1 to end of array\n");
    addDynArr(da, 1);
    printf("Size of array - (Should be 1): %d\n", sizeDynArr(da));
    printf("Get element at index 0 - (Should be 1): %d\n", getDynArr(da, 0));

    printf("Put element 0 into array position 0 \n");
    putDynArr(da, 0, 0); //will cause error
    printf("Size of array - (Should be 1): %d\n", sizeDynArr(da));
    printf("Get position 0  - (Should be 0): %d\n", getDynArr(da, 0));

    printf("Add 5 elements to end of array (1,2,3,4,5)\n");

    addDynArr(da, 1);
    addDynArr(da, 2);
    addDynArr(da, 3);
    addDynArr(da, 4);
    addDynArr(da, 5);

    printf("Size of array - (Should be 6): %d\n", sizeDynArr(da));
    printf("View all elements in array\n");
    for(i = 0; i < da->size; i++)
    {
        printf("%d, ", da->data[i]) ;
    }
    printf("\n");

    printf("Remove at array index 5\n");

    removeAtDynArr(da, 5);
    printf("View all elements in array\n");

    for(i = 0; i < da->size; i++)
    {
        printf("%d, ", da->data[i]) ;
    }
    printf("\n");
    printf("Size of array - (Should be 5): %d\n", sizeDynArr(da));

    printf("Swap array index  4 with 1\n");
    swapDynArr(da, 4,0);
    printf("View all elements in array\n");

    for(i = 0; i < da->size; i++)
    {
        printf("%d, ", da->data[i]) ;
    }
    printf("\n");
    printf("freeing memory\n");
    freeDynArr(da);

    printf("Size of array - (Should be 0): %d\n", sizeDynArr(da));

    printf("\n");
    printf("Testing Stack ADT\n");
    initDynArr(da, 5);
    printf("Is the stack empty - (1 yes, 0 no): %d\n", isEmptyDynArray(da));

    printf("Adding element (1,2,3,4,5) on to stack\n");

    pushDynArray(da,1);
    pushDynArray(da,2);
    pushDynArray(da,3);
    pushDynArray(da,4);
    pushDynArray(da,5);
    printf("Size of Stack - (Should be 5): %d\n", sizeDynArr(da));





    printf("Is the stack empty - (1 yes, 0 no): %d\n", isEmptyDynArray(da));
    printf("View all elements in stack\n");
    printf("Add at 3\n");
    dynArrayAddAt(da, 1, 5);


    for(i = 0; i < da->size; i++)
    {
        printf("%d, ", da->data[i]) ;
    }
    printf("\n");

    printf("Pop Top\n");
    popDynArray(da);
    printf("Get Top of Stack - (Should be 4): %d\n", topDynArray(da));

    printf("Pop Top\n");
    popDynArray(da);
    printf("Get Top of Stack - (Should be 3): %d\n", topDynArray(da));

    printf("Pop Top\n");
    popDynArray(da);
    printf("Get Top of Stack - (Should be 2): %d\n", topDynArray(da));

    printf("Pop Top\n");
    popDynArray(da);
    printf("Get Top of Stack - (Should be 1): %d\n", topDynArray(da));

    printf("Pop Top last element \n");
	popDynArray(da);



    printf("Is the stack empty - (1 yes, 0 no): %d", isEmptyDynArray(da));

    printf("\n");


    return 0;
}

