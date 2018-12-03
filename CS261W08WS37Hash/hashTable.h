/*
 * hashTable.h
 *
 *  Created on: Aug 12, 2013
 *      Author: Jeff Rix
 *      CS261 Worksheet 37
 *      Implements the open address hash table
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#ifndef TYPE
#define TYPE char *
#endif

struct openHashTable;

int openHashTableSize(struct openHashTable *ht);
void initOpenHashTable(struct openHashTable *ht, int size);
void openHashTableAdd(struct openHashTable *ht, TYPE newValue);
int openHashTableContains(struct openHashTable *ht, TYPE newValue);

#endif /* HASHTABLE_H_ */
