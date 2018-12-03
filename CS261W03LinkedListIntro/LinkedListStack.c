/*
 * LinkedListStack.c
 *
 *  Created on: Jul 11, 2013
 *      Author: jeff
 *      Worksheet 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# ifndef TYPE
# define TYPE int
# endif




struct link {
	TYPE value;
	struct link * next;
};

struct linkedListStack
{
	struct link *firstLink;
};

void linkedListStackInit (struct linkedListStack * s)
{
	s->firstLink = 0;
}

int linkedListStackIsEmpty (struct linkedListStack *s)
{
	if (s->firstLink == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

void linkedListStackPush (struct linkedListStack *s, TYPE d)
{
	struct link *newLink =  malloc(sizeof(struct link));
	assert (newLink != 0);
	newLink->value = d;
	newLink->next = s->firstLink;
	s->firstLink = newLink;
}

TYPE linkedListStackTop (struct linkedListStack *s)
{
	assert(linkedListStackIsEmpty(s) == 1);

	return s->firstLink->value;
}

void linkedListStackPop (struct linkedListStack *s)
{
	assert(linkedListStackIsEmpty(s) == 1);

	s->firstLink =  s->firstLink->next;
}



void linkedListStackFree (struct linkedListStack *s)
{
	while (!linkedListStackIsEmpty(s))
	{
		linkedListStackPop(s);
	}
}

int main()
{
	struct linkedListStack *s = malloc(sizeof(struct linkedListStack));

	linkedListStackInit(s);
	linkedListStackPush(s, 1);
	linkedListStackPush(s, 2);
	linkedListStackPush(s, 3);
	linkedListStackPush(s, 4);

	printf("added (1,2,3,4) to stack, top it (4): %d\n", linkedListStackTop(s));

	linkedListStackPop(s);
	linkedListStackPop(s);

	printf("removed (3,4) from  stack, top it (2): %d\n", linkedListStackTop(s));





	printf("hello world");
	return 0;
}
