/*
 * hashTableBuckets.c
 *
 *  Created on: Aug 16, 2013
 *      Author: jeff
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashTableBuckets.h"

struct hlink {
	TYPE value;
	struct hlink *next;
};

struct hashTable {
	struct hlink ** table;
	int tablesize;
	int count;
};


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


/* Function that initialized the char array for the hash table
	param: 	ht		pointer to a char array
	param:	size 	set the array capacity to this value
	pre:	ht is not empty
	post:	initialize the table array with null values
*/
void initHashTable (struct hashTable * ht, int size)
{
	int index;

	if(ht == 0)
		return;
	ht->table = malloc(sizeof(struct hlink*) * size);
	ht->tablesize = size;
	ht->count = 0;
	for(index = 0; index < size; index++)
		ht->table[index] = 0;
}


/* Function gets size of hash table : number of elements in hash table
	param: 	ht		pointer to a char array
	pre:	ht is not null
	post:	none
	return: count of hash table elements
*/
int hashTableSize (struct hashTable * ht)
{
	assert(ht != 0);
	return ht->count;
}


/* Function that adds a new value to the hash table
	param: 	ht		pointer to a char array
	param:	newValue 	TYPE value
	pre:	ht is not null
	post:	value is added to hash table
*/
void hashTableAdd (struct hashTable *ht, TYPE newValue) {
// compute hash value to find the correct bucket
	assert(ht != 0);

	int hashIndex = HASH(newValue) % ht->tablesize;
	if (hashIndex < 0)
		hashIndex += ht->tablesize;
	struct hlink * newLink = (struct hlink *) malloc(sizeof(struct hlink));
	assert(newLink);
	newLink->value = newValue;
	newLink->next = ht->table[hashIndex];
	ht->table[hashIndex] = newLink; /* add to bucket */
	ht->count++;

	if ((ht->count / (double) ht->tablesize) > 8.0)
	{
		resizeTable(ht);
	}
}



/* Function that checks if value is in hash table
	param: 	ht		pointer to a char array
	param:	testValue 	the value to search for
	pre:	ht is not null
	post:	none
	return: 1 found value, 0 did not find value
*/
int hashTableContains (struct hashTable * ht, TYPE testElement) {
	assert(ht != 0);

	int hashIndex = HASH(testElement) % ht->tablesize;
	if (hashIndex < 0)
		hashIndex += ht->tablesize;
	//loop through linked list
	if (ht->table[hashIndex] != 0)
	{
		struct hlink *currentLink = ht->table[hashIndex];

		while(currentLink != 0)
		{
			if(strcmp(currentLink->value, testElement) == 0)
			{
				return 1;
			}

			currentLink = currentLink->next;
		}
	}

	return 0;
}



/* Function that doubles the capacity of the hash table
	param: 	ht			pointer to a char array
			testElement	element value to remove
	pre:	ht is not null
	post:	element is removed form hash table
*/
void hashTableRemove (struct hashTable * ht, TYPE testElement) {
	assert(ht != 0);

	int hashIndex = HASH(testElement) % ht->tablesize;
	if (hashIndex < 0)
		hashIndex += ht->tablesize;


	//loop through linked list
	struct hlink *currentLink = ht->table[hashIndex];
	struct hlink *previousLink = 0;

	while(currentLink != 0)
	{
		if(strcmp(currentLink->value, testElement) == 0)
		{
			if(previousLink == 0)
			{
				ht->table[hashIndex] = currentLink->next;
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
}


/* Function that doubles the capacity of the hash table
	param: 	ht		pointer to a char array
	pre:	ht is not null
	post:	table of Hash table capacity it doubled
*/
void resizeTable (struct hashTable *ht) {
	assert(ht != 0);
	int newSize = ht->tablesize * 2;

	struct hashTable *htNew = malloc(sizeof(struct hashTable));

	initHashTable(htNew, newSize);

	if(ht->count > 0)
	{
		int i;
		for(i = 0; i < ht->tablesize; i++)
		{
			if (ht->table[i] != 0)
			{
				struct hlink *currentLink = ht->table[i];

				while(currentLink != 0)
				{
					hashTableAdd(htNew, ht->table[i]->value);

					currentLink = currentLink->next;
				}
			}
		}
	}
	free(ht->table);
	ht->table = htNew->table;
	ht->tablesize = newSize;
}

/* Prints all elements of hash table, even empty indexes
	param: 	ht		pointer to a char array
	pre:	ht is not null
	post:	none
*/
void printHashMap(struct hashTable *ht)
{

	if(ht->count > 0)
	{
		int i;
		for(i = 0; i < ht->tablesize; i++)
		{
			if (ht->table[i] != 0)
			{
				struct hlink *currentLink = ht->table[i];

				while(currentLink != 0)
				{
					printf("%s\n" ,currentLink->value);

					currentLink = currentLink->next;
				}
			}
		}
	}

}



int main (int argc, const char * argv[])
{
	struct hashTable *ht = malloc(sizeof(struct hashTable));
	initHashTable(ht, 5);
	printf("Table Size (0): %d\n", hashTableSize(ht));
	printf("Add Pie, Cake, Cookie to hash table\n");
	hashTableAdd(ht, "Pie");
	hashTableAdd(ht, "Cake");
	hashTableAdd(ht, "Cookie");
	printf("Table Size (3): %d\n", hashTableSize(ht));
	printf("Check if Table contains Pie (1): %d\n", hashTableContains(ht, "Pie"));
	printf("Check if Table contains Berry (0): %d\n", hashTableContains(ht, "Berry"));
	printf("Print Hash:\n");
	printHashMap(ht);
	printf("Remove Cookie from hash table\n");
	hashTableRemove(ht, "Cookie");
	printf("Print Hash Table:\n");
	printHashMap(ht);
	printf("Add Candy, Sugar, Chocolate to hash table\n");
	hashTableAdd(ht, "Candy");
	hashTableAdd(ht, "Sugar");
	hashTableAdd(ht, "Chocolate");
	printf("Print Hash Table:\n");
	printHashMap(ht);
	printf("Add Mint to hash table\n");
	hashTableAdd(ht, "Mint");
	printf("Print Hash Table:\n");
	printHashMap(ht);
	printf("Table Size (6): %d\n", hashTableSize(ht));

}
