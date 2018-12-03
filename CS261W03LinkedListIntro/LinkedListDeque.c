/*
 * LinkedListDeque.c
 *
 *  Created on: Jul 11, 2013
 *      Author: JeffR
 *      Worksheet 19
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# ifndef TYPE
# define TYPE int
# endif

struct dlink {
	TYPE value;
	struct dlink * next;
	struct dlink * prev;
};

struct linkedList {
	int size;
	struct dlink * frontSentinel;
	struct dlink * backSentinel;
};

/* these functions are written for you */
void LinkedListInit (struct linkedList *q) {
	q->frontSentinel = malloc(sizeof(struct dlink));
	assert(q->frontSentinel != 0);
	q->backSentinel = malloc(sizeof(struct dlink));
	assert(q->backSentinel != 0);
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinel;
	q->frontSentinel->prev = 0;
	q->backSentinel->next = 0;
	q->size = 0;
}

int LinkedListIsEmpty (struct linkedList *q) {
	return q->size == 0;
}


/* _addBefore places a new link BEFORE the provide link, lnk */
void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e) {
	struct dlink *d = malloc(sizeof(struct dlink));
	d->value = e;
	lnk->prev->next = d;
	d->prev = lnk->prev;
	lnk->prev = d;
	d->next = lnk;
	q->size++;
}

void _removeLink (struct linkedList *q, struct dlink *lnk) {
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	q->size--;
}

TYPE LinkedListFront (struct linkedList *q) {
	assert(!LinkedListIsEmpty(q));
	return q->frontSentinel->next->value;
}
TYPE LinkedListBack (struct linkedList *q) {
	assert(! LinkedListIsEmpty(q));

	return q->backSentinel->prev->value;
}


void LinkedListAddFront (struct linkedList *q, TYPE e)
{
	_addBefore(q, q->frontSentinel->next, e);
}

void LinkedListAddback (struct linkedList *q, TYPE e)
{
	_addBefore(q, q->backSentinel, e);
}

void linkedListRemoveFront (struct linkedList *q) {
	assert(! LinkedListIsEmpty(q));
	_removeLink (q, q->frontSentinel->next);
}

void LinkedListRemoveBack (struct linkedList *q) {
	assert(! LinkedListIsEmpty(q));
	_removeLink (q, q->backSentinel->prev);
}



void linkedListFree (struct linkedList *q) {
	while (q->size > 0)
		linkedListRemoveFront(q);
	free (q->frontSentinel);
	free (q->backSentinel);
	q->frontSentinel = q->backSentinel = 0;
}


int main()
{
	struct linkedList *q = malloc(sizeof(struct linkedList));
	LinkedListInit(q);

	LinkedListAddFront(q, 2);
	LinkedListAddback(q, 3);
	printf("see front (2) %d\n", LinkedListFront(q));
	printf("see back (3) %d\n", LinkedListBack(q));

	LinkedListAddFront(q, 1);
	LinkedListAddback(q, 4);

	printf("see front (1) %d\n", LinkedListFront(q));
	printf("see back (4) %d\n", LinkedListBack(q));

	LinkedListRemoveBack(q);
	printf("see back (3) %d\n", LinkedListBack(q));

	linkedListRemoveFront(q);
	printf("see back (2) %d\n", LinkedListFront(q));



	printf("hello world");
	return 0;
}
