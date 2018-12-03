/*
  BagADT.c
  Dynamic Array Implementation Covering Bag ADT
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

void _dynArrayRemoveAt (struct DynArr * da, int index) {
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

void removeDynArr (struct DynArr * da, TYPE test) {
    int i;
    for (i = 0; i < da->size; i++)
    {
        if (EQ(test, da->data[i]))
        { /* found it */
            _dynArrayRemoveAt(da, i);
            return;
        }
    }
}

int containsDynArr (struct DynArr * da, TYPE e)
{
    int i;
    for (i = 0; i < da->size; i++)
    {
        if(EQ(e, da->data[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Not much to see here!\n");
    return 0;
}

