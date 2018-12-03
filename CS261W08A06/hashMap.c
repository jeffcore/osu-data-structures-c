/*	hashMap.c: Hash Table Implementation of Concordance
 * 	Jeff Rix
 *  CS261 Assignment 6
 *  8/15/13
 *
 *  */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"


/* Hash 1  function
	param: 	str		pointer to a char arra
	pre: none
	return: r   index number to place element
*/
int stringHash1(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += str[i];   /*takes the ascii value of each letter and adds it together */
    return r;
}

/* Hash 2  function
	param: 	str		pointer to a char arra
	pre: none
	return: r   index number to place element
*/
int stringHash2(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
    return r;
}

/* Function initialize the supplied hashMap struct
	param: 	ht		pointer to a hash map
	param:	size 	set the array capacity to this value
	pre:	ht is not empty
	post:	initialize the hash table with null values
*/
void initMap (struct hashMap * ht, int tableSize)
{
    assert(ht != 0);

	int index;
    
    if(ht == 0)
        return;
    ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
    ht->tableSize = tableSize;
    ht->count = 0;
    for(index = 0; index < tableSize; index++)
        ht->table[index] = 0;
}

/* Function that frees all memory used form hashMap
	param: 	ht		pointer to a hash map
	pre:	ht is not empty
	post:	all memory of hashMap is freed
*/
void freeMap (struct hashMap * ht)
{
	assert(ht != 0);
	/*write this*/
	/*loop through entire array*/
	int i;
	for(i = 0; i < ht->tableSize; i++)
	{
		/*if element is not empty loop through and remove linked list elements*/
		if(ht->table[i] != 0)
		{
			while(ht->table[i]!=0)
			{
				/*remove key*/
				removeKey(ht, ht->table[i]->key);
			}
			/*free element*/
			free(ht->table[i]);
		}
	}
	/*reset count and tablesize*/
	free(ht->table);
	ht->count = 0;
	ht->tableSize = 0;
}

/* Function that doubles the capacity of the hash table
	param: 	ht		pointer to a hash map
	pre:	ht is not null
	post:	array of Hash table capacity is doubled
*/
void _resizeTable(struct hashMap *ht)
{
	assert(ht != 0);

	int oldSize = ht->tableSize;


	struct hashLink **oldTable = ht->table;

	initMap(ht, oldSize * 2);

	int i;
	for(i = 0; i < oldSize; i++)
	{
		if (oldTable[i] != 0)
		{
			struct hashLink *currentLink = oldTable[i];

			while(currentLink != 0)
			{
				insertMap(ht, currentLink->key,  currentLink->value);

				struct hashLink *freeLink = currentLink;
				currentLink = currentLink->next;
				free(freeLink);
			}
		}
	}
	free(oldTable);

}

/* Function that adds a new value to the hash table
	param: 	ht		pointer to a hash map
	param:	v 	TYPE value
	pre:	ht is not null
	post:	value is added to hash table
*/
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	assert(ht != 0);
	/*get hash*/
	int idx;

	if (HASHING_FUNCTION == 1)
	{
		idx= stringHash1(k) % ht->tableSize;
	}
	else
	{
		idx = stringHash2(k) % ht->tableSize;
	}

    if(idx < 0)
    {
    	idx += ht->tableSize;
    }

    if(containsKey(ht, k))
    {
    	struct hashLink *currentLink = ht->table[idx];

		while(currentLink != 0)
		{
			if(strcmp(currentLink->key, k) == 0)
			{
				currentLink->value++;
			}

			currentLink = currentLink->next;
		}
    }
    else
    {
		struct hashLink * newLink = (struct hashLink *) malloc(sizeof(struct hashLink));
		assert(newLink != 0);
		newLink->key = k;
		newLink->value = v;
		newLink->next = ht->table[idx]; //current link at the top goes after new link
		ht->table[idx] = newLink; //beginning of bucket gets pointer to new link
		ht->count++;
    }

    if (tableLoad(ht) > 8.0)
	{
		_resizeTable(ht);
	}

	/*write this*/
}

/* Function that this returns a POINTER to the value stored in a hashLink specified by the key k.
	param: 	ht		pointer to a hash map
	param:	k  	TYPE key
	pre:	ht is not null
	return: returns a POINTER to the value stored in a hashLink specified by the key k, returns null if not found
	post:	none
*/
ValueType* atMap (struct hashMap * ht, KeyType k)
{
    /*write this*/
    assert(ht != 0);

    int idx;
	if (HASHING_FUNCTION == 1)
	{
		idx= stringHash1(k) % ht->tableSize;
	}
	else
	{
		idx = stringHash2(k) % ht->tableSize;
	}

	if(idx < 0)
	{
		idx += ht->tableSize;
	}

	//loop through linked list
	struct hashLink *currentLink = ht->table[idx];

	while(currentLink != 0)
	{
		if(strcmp(currentLink->key, k) == 0)
		{
			//ValueType *prt = &currentLink->value;
			return &currentLink->value;
		}

		currentLink = currentLink->next;
	}

	return NULL;
}


/* Function that checks if value is in hash map
	param: 	ht		pointer to a hash map
	param:	k 	KeyType key of mash map
	pre:	ht is not null
	post:	none
	return: 1 found value, 0 did not find value
*/
int containsKey (struct hashMap * ht, KeyType k)
{
    /*write this*/

	assert(ht != 0);

    int idx;
	if (HASHING_FUNCTION == 1)
	{
		idx= stringHash1(k) % ht->tableSize;
	}
	else
	{
		idx = stringHash2(k) % ht->tableSize;
	}


	if(idx < 0)
	{
		idx += ht->tableSize;
	}

	//loop through linked list
	if (ht->table[idx] != 0)
	{
		struct hashLink *currentLink = ht->table[idx];

		while(currentLink != 0)
		{
			if(strcmp(currentLink->key, k) == 0)
			{
				return 1;
			}

			currentLink = currentLink->next;
		}
	}

    return 0;
}


/* Function that doubles the capacity of the hash table
	param: 	ht		pointer to a hash map
			k 		KeyType key of mash map
	pre:	ht is not null
	post:	element is removed from hash table
*/
void removeKey (struct hashMap * ht, KeyType k)
{

	assert(ht != 0);

    int idx;
	if (HASHING_FUNCTION == 1)
	{
		idx= stringHash1(k) % ht->tableSize;
	}
	else
	{
		idx = stringHash2(k) % ht->tableSize;
	}


	if(idx < 0)
	{
		idx += ht->tableSize;
	}

	//loop through linked list
	struct hashLink *currentLink = ht->table[idx];
	struct hashLink *previousLink = 0;

	while(currentLink != 0)
	{
		if(strcmp(currentLink->key, k) == 0)
		{
			if(previousLink == 0)
			{
				ht->table[idx] = currentLink->next;
			}
			else
			{
				previousLink->next = currentLink->next;
			}

			free(currentLink);
			ht->count--;
			return;
		}
		else
		{
			previousLink = currentLink;
			currentLink = currentLink->next;
		}
	}

	printf("Did not find the value.");

	/*write this*/
}


/* Function gets size of hash map : number of elements in hash table
	param: 	ht		pointer to a hash map
	pre:	ht is not null
	post:	none
	return: count of hash map elements
*/
int size (struct hashMap *ht)
{
    assert(ht != 0);
    return ht->count;
}

/* Function gets capacity of hash map
	param: 	ht		pointer to a hash map
	pre:	ht is not null
	post:	none
	return: capacity of hash map
*/
int capacity(struct hashMap *ht)
{
    /*write this*/
	assert(ht != 0);
    return ht->tableSize;
}

/* Function counts the number of empty buckets in hash map
	param: 	ht		pointer to a hash map
	pre:	ht is not null
	post:	none
	return: total number of empty buckets in hash map
*/
int emptyBuckets(struct hashMap *ht)
{
	assert(ht != 0);
	/*write this*/
	int i;
	int totalEmpty = 0;
	for(i = 0; i < capacity(ht); i++)
	{
		if(ht->table[i] == 0)
		{
			totalEmpty++;
		}
	}

    return totalEmpty;
}


/* Function that calculates the table load
	param: 	ht		pointer to a hash map
	pre:	ht is not null
	post:	none
	return: float table load
*/
float tableLoad(struct hashMap *ht)
{
    /*write this*/
	assert(ht != 0);

    return (float)ht->count/(float)ht->tableSize;
}

/* Function prints out the contents of the hash map
	param: 	ht		pointer to a hash map
	pre:	ht is not null
	post:	none
	return: none
*/
void printHashMap(struct hashMap *ht)
{
	assert(ht != 0);

	if(size(ht) > 0)
	{
		int i;
		for(i = 0; i < capacity(ht); i++)
		{
			if (ht->table[i] != 0)
			{
				struct hashLink *currentLink = ht->table[i];

				while(currentLink != 0)
				{
					printf("%s: %d\n" ,currentLink->key,  currentLink->value);

					currentLink = currentLink->next;
				}
			}
		}
	}

}

