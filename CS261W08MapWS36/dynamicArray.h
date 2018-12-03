/* 	dynArr.h : Dynamic Array implementation. */
#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1

# ifndef TYPE
# define TYPE      void*
# endif



struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

typedef struct DynArr DynArr;
//typedef struct association *(*comparator)(void *left, void*right);
struct bag;


/* Dynamic Array Functions */
DynArr *createDynArr(int cap);
void deleteDynArr(DynArr *v);

int sizeDynArr(DynArr *v);

void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, int pos);
void putDynArr(DynArr *v, int pos, TYPE val);
void swapDynArr(DynArr *v, int i, int  j);
void removeAtDynArr(DynArr *v, int idx);
#endif
