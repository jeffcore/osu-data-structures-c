/*
 * hashTableBuckets.h
 *
 *  Created on: Aug 16, 2013
 *      Author: jeff
 */

#ifndef HASHTABLEBUCKETS_H_
#define HASHTABLEBUCKETS_H_



#ifndef TYPE
#define TYPE char *
#endif

struct hlink;
struct hashTable;

int HASH(char *str);
void initHashTable (struct hashTable * ht, int size);
int hashTableSize (struct hashTable * ht);
void hashTableAdd (struct hashTable *ht, TYPE newValue);
int hashTableContains (struct hashTable * ht, TYPE testElement);
void hashTableRemove (struct hashTable * ht, TYPE testElement);
void resizeTable (struct hashTable *ht);
void printHashMap(struct hashTable *ht);

#endif /* HASHTABLEBUCKETS_H_ */
