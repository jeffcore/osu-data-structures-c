/*
 * dyarraydict.h
 *
 *  Created on: Aug 11, 2013
 *      Author: jeff
 */

#ifndef DYARRAYDICT_H_
#define DYARRAYDICT_H_

/*
dynamic array dictionary interface file
*/

# ifndef KEYTYPE
# define KEYTYPE char *
# endif

# ifndef VALUETYPE
# define VALUETYPE double
# endif

struct association {
	KEYTYPE key;
	VALUETYPE value;

};


# define TYPE struct association *
# include "dynamicArray.h"

/* dictionary */

VALUETYPE dyArrayDictionaryGet (struct DynArr * da, KEYTYPE key);
void dyArrayDictionaryPut (struct DynArr * da, KEYTYPE key, VALUETYPE val);
int dyArrayDictionaryContainsKey (struct DynArr * da, KEYTYPE key);
void dyArrayDictionaryRemove (struct DynArr *da, KEYTYPE key);




#endif /* DYARRAYDICT_H_ */
