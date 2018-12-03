/*
 * dyarraydict.c
 *
 *  Created on: Aug 11, 2013
 *      Author: jeff
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dyarraydict.h"


int _compare(KEYTYPE lValue, KEYTYPE rValue);
void printArray(struct DynArr *da);


/*finds and places the value associated with key in valptr
	param: 	da		pointer to the dynamic array
			key		key type
	pre:	da is not null
	post:	none
	ret:	value of key
*/

VALUETYPE dyArrayDictionaryGet (struct DynArr *da, KEYTYPE key)
{
	assert(da != 0);

	VALUETYPE ret = 0;

	for(int i = 0;i < da->size; i++)
	{
		if((*_compare)(((struct association *)(da->data[i]))->key, key) == 0)
		{
			ret = ((struct association *)(da->data[i]))->value;
			break;
		}

	}
	return ret;
}

/*puts association into dynamic array
	param: 	da		pointer to the dynamic array
			key		key type
			val		value of the key
	pre:	da is not null
	post:	adds association to dynamic array
	ret:	none
*/
void dyArrayDictionaryPut (struct DynArr *da, KEYTYPE key, VALUETYPE val) {
	assert(da != 0);

	struct association * ap;
	if (dyArrayDictionaryContainsKey(da, key))
		dyArrayDictionaryRemove(da, key);
	ap = (struct association *) malloc(sizeof(struct association));
	assert(ap != 0);
	ap->key = key;
	ap->value = val;
	addDynArr(da, ap);
}


/* checks if a key is in the dynamic array
	param: 	da		pointer to the dynamic array
			key		key type
	pre:	da is not null
	post:	none
	ret:	1 for true, 0 for false
*/
int dyArrayDictionaryContainsKey (struct DynArr *da, KEYTYPE key)
{
	assert(da != 0);

	for(int i = 0; i < da->size; i++)
	{
		if((*_compare)(((struct association *)(da->data[i]))->key, key) == 0)
			return 1;
	}
	return 0;
}

/* removes association from dynamic array
	param: 	da		pointer to the dynamic array
			key		key type
	pre:	da is not null
	post:	association is removed from dynamic array
	ret:	none
*/

void dyArrayDictionaryRemove (struct DynArr *da, KEYTYPE key)
{
	assert(da != 0);

	for(int i = 0;i < da->size; i++)
	{
		if((*_compare)(((struct association *)(da->data[i]))->key, key) == 0)
		{
			free(((struct association *)(da->data[i]))->key);
			free((struct association *)(da->data[i]));
			removeAtDynArr(da, i);
			break;
		}
	}
}


/*  compares values in an association
	param: 	lvalue left value
			rvalue right value
	pre:	none
	post:	none
	ret:	0 for equals, -1 for left less than right, 1 for left greater than right
*/
int _compare(KEYTYPE lValue, KEYTYPE rValue)
{
   return strcmp(lValue, rValue);
}


/*  prints contents of associations in array
	param: 	da		pointer to the dynamic array
	pre:	da is not null
	post:	none
	ret:	none
*/
void printArray(struct DynArr *da)
{
	assert(da != 0);

	for (int i = 0; i < da->size; ++i)
	{
		struct association *element = (struct association *)(da->data[i]);
		printf("KEY: %s  VALUE: %f\n", element->key, element->value);
	}
}

int main (int argc, const char * argv[]) {

	struct DynArr *da = createDynArr(100);

	printf("Add: Awesome: 22.2, Sauce: 12.2, Mustard: 5.22\n");
	dyArrayDictionaryPut(da, "Awesome", 22.2);
	dyArrayDictionaryPut(da, "Sauce", 12.2);
	dyArrayDictionaryPut(da, "Mustard", 5.22);
	printf("Print It out\n");

	printArray(da);

	printf("Change Mustard to 33.3\n");
	dyArrayDictionaryPut(da, "Mustard", 33.3);

	printf("Print It out\n");
	printArray(da);

	printf("Get Mustard's value (should be 33.3) : %f\n", dyArrayDictionaryGet(da, "Mustard"));

	printf("Check if Awesome really exists (hell yes it does): %d\n", dyArrayDictionaryContainsKey(da, "Awesome"));

	printf("Remove Awesome, this program is not cool enough.\n");

	dyArrayDictionaryRemove(da, "Awesome");

	printf("Print It out\n");
		printArray(da);


	return 0;
}
