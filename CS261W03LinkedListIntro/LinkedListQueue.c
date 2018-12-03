/*
 * LinkedListQueue.c
 *
 *  Created on: Jul 11, 2013
 *      Author: JeffR
 *      Worksheet 18
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# ifndef TYPE
# define TYPE int
# endif

struct link
{
	TYPE value;
	struct link * next;
};

struct listQueue
{
	struct link *firstLink;
	struct link *lastLink;
};

int listQueueIsEmpty (struct listQueue *q)
{
	if(q->firstLink->next == 0 && q->lastLink->next == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void listQueueInit (struct listQueue *q)
{
	struct link *lnk = (struct link *) malloc(sizeof(struct link));
	assert(lnk != 0); /* lnk is the sentinel */
	lnk->next = 0;
	q->firstLink = q->lastLink = lnk;
}
void listQueueAddBack (struct listQueue *q, TYPE e)
{
	struct link *lnk = malloc(sizeof(struct link));
	assert(lnk != 0);

	lnk->value = e;
	lnk->next = 0;
	q->lastLink->next = lnk;
	q->lastLink = lnk;
}

TYPE listQueueFront (struct listQueue *q)
{
	assert(listQueueIsEmpty(q) == 0);

	return q->firstLink->next->value;
}

void listQueueRemoveFront (struct listQueue *q)
{
	assert(listQueueIsEmpty(q) == 0);

	q->firstLink->next = q->firstLink->next->next;
}

int main()
{
	struct listQueue *q = malloc(sizeof(struct listQueue));
	listQueueInit(q);

	listQueueAddBack(q, 1);
	listQueueAddBack(q, 2);
	listQueueAddBack(q, 3);
	listQueueAddBack(q, 4);
	printf("added (1,2,3,4), see front (1) %d\n", listQueueFront(q));
	listQueueRemoveFront(q);
	printf("removed  (1), see front (2 ) %d\n", listQueueFront(q));

	printf("hello world");
	return 0;
}








