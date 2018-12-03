/*
 * hashTable.c
 *
 *  Created on: Aug 12, 2013
 *      Author: Jeff Rix
 *      CS261 Worksheet 37
 *      Implements the open address hash table
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashTable.h"

/* Open Hash Table Struct */
struct openHashTable {
	TYPE * table;
	int tablesize;
	int count;
};

/* Internal Function Prototype */
void _resizeOpenHashTable (struct openHashTable *ht);


/* Hash function
	param: 	str		pointer to a char arra
	pre: none
	return: r   index number to place element
*/
int HASH(char *str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
	r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

int stringHash1(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += str[i];
    return r;
}

int stringHash2(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
    return r;
}



/* Function gets size of hash table : number of elements in hash table
	param: 	ht		pointer to a char array
	pre:	ht is not null
	post:	none
	return: count of hash table
*/
int openHashTableSize (struct openHashTable *ht)
{
	assert(ht != 0);
	return ht->count;
}

/* Function that initialized the char array for the hash table
	param: 	ht		pointer to a char array
	param:	size 	set the array capacity to this value
	pre:	ht is not empty
	post:	initialize the table array with null values
*/
void initOpenHashTable (struct openHashTable * ht, int size)
{
	int i;
	assert (size > 0);
	ht->table = (TYPE *) malloc(size * sizeof(TYPE *));
	assert(ht->table != 0);
	for (i = 0; i < size; i++)
		ht->table[i] = 0; /* initialize empty */

	ht->tablesize = size;
	ht->count = 0;
}

/* Function that doubles the capacity of the hash table
	param: 	ht		pointer to a char array
	pre:	ht is not null
	post:	table of Hash table capacity it doubled
*/
void _resizeOpenHashTable (struct openHashTable *ht)
{
	assert(ht != 0);

	int newSize = ht->tablesize * 2;

	struct openHashTable *htNew = malloc(sizeof(struct openHashTable));

	initOpenHashTable(htNew, newSize);


	int i;
	for(i = 0; i < ht->tablesize; i++)
	{
		if(ht->table[i] != 0)
		{
			openHashTableAdd(htNew, ht->table[i]);
		}
	}
	free(ht->table);
	ht->table = htNew->table;
	ht->tablesize = newSize;

}

/* Function that adds a new value to the hash table
	param: 	ht		pointer to a char array
	param:	newValue 	TYPE value
	pre:	ht is not null
	post:	value is added to hash table
*/
void openHashTableAdd (struct openHashTable * ht, TYPE newValue)
{
	assert(ht != 0);

	int idx;
	/* Make sure we have space and under the load factor threshold*/
	if ((ht->count / (double) ht->tablesize) > 0.75)
		_resizeOpenHashTable(ht);

	ht->count++;
	idx = HASH(newValue) % ht->tablesize;
	/* To be safe, use only positive arithmetic.  % may behave very differently on diff
	implementations or diff languages .  However, you can do the following to deal with a
	negative result from HASH */
	if (idx < 0)
		idx += ht->tablesize;

	while (ht->table[idx] != 0)
	{
		if(idx == ht->tablesize - 1)
		{
			idx = 0;
		}
		else
		{
			idx++;
		}
	}
	ht->table[idx] = newValue;
}

/* Function that checks if value is in hash table
	param: 	ht		pointer to a char array
	param:	testValue 	the value to search for
	pre:	ht is not null
	post:	none
	return: 1 found value, 0 did not find value
*/
int openHashTableBagContains (struct openHashTable *ht, TYPE  testValue)
{
	assert(ht != 0);
	int idx;
	int retValue = 0;
	idx = HASH(testValue) % ht->tablesize;
	if (idx < 0)
		idx += ht->tablesize;

	while (ht->table[idx] != 0)
	{
		if(strcmp(ht->table[idx], testValue) == 0)
		{
			retValue = 1;
			break;
		}
		else if (idx == ht->tablesize - 1)
		{
			idx = 0;
		}
		else
		{
			idx++;
		}
	}

	return retValue;
}

/* Prints all elements of hash table, even empty indexes
	param: 	ht		pointer to a char array
	pre:	ht is not null
	post:	none
*/
void printList(struct openHashTable *ht)
{
	assert(ht != 0);
	int i;
	for(i = 0; i < ht->tablesize; i++)
	{
		printf("%s\n", ht->table[i]);
	}

}

int main (int argc, const char * argv[])
{
	struct openHashTable *ht = malloc(sizeof(struct openHashTable));
	initOpenHashTable(ht, 5);

	printf("Add Mars, Jupiter, Pluto to hash table.\n");
	openHashTableAdd(ht, "Mars");
	openHashTableAdd(ht, "Jupiter");
	openHashTableAdd(ht, "Pluto");

	printf("Does the Solar System Contain Mars (should be yes): %d\n", openHashTableBagContains(ht, "Mars"));

	printf("Print Hash Table\n");
	printList(ht);

	printf("the size of the table (should be 3): %d\n", openHashTableSize(ht));

	printf("Add Venus, Neptune to hash table.\n");
	openHashTableAdd(ht, "Venus");
	openHashTableAdd(ht, "Neptune");
	printf("Print Hash Table\n");
	printList(ht);
	printf("Add Earth, Mercury to hash table.\n");
	openHashTableAdd(ht, "Earth");
	openHashTableAdd(ht, "Mercury");
	printf("Print Hash Table\n");
	printList(ht);
	printf("Does the Solar System Contain Pluto (should be yes, but not in real life): %d\n", openHashTableBagContains(ht, "Mars"));
	printf("Does the Solar System Contain Earth (should be yes): %d\n", openHashTableBagContains(ht, "Mars"));
	printf("the size of the table (should be 7): %d\n", openHashTableSize(ht));


	printf("Testing String Hash1 listen %d\n", stringHash1("listen"));
	printf("Testing String Hash1 silent %d\n", stringHash1("silent"));


	printf("Testing String Hash2 %d\n", stringHash2("hello"));




}
