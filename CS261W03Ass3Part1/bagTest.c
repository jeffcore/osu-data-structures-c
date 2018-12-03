/*
 * bagTest.c
 *
 *  Created on: Jul 15, 2013
 *      Author: jeff
 */
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main()
{
	struct linkedList* b = createLinkedList();
	addList(b, 1);

	addList(b, 1);
	addList(b, 3);
	addList(b, 4);
	addList(b, 5);
	printf("adding 1,3,4,5\n");
	printf("contains 3 : %d\n", containsList(b, 3));
	printf("contains 6 : %d\n", containsList(b, 6));
	//_printList(b);
	printf("Remove 3\n");
	removeList(b,3);
	printf("contains 3 : %d\n", containsList(b, 3));
	printf("Remove 5\n");
	removeList(b,5);
	printf("contains 5 : %d\n", containsList(b, 5));
	printf("adding 7\n");
	addList(b, 7);
	printf("contains 7 : %d\n", containsList(b, 7));
	printf("contains 1 : %d\n", containsList(b, 1));


	printf("hello2");
	deleteLinkedList(b);
	return 0;
}
