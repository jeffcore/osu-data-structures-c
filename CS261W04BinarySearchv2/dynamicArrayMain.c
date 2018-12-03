#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {	
	DynArr* b;

	b = createDynArr(5);
		
	
	orderedArrayAdd(b, 5); /*Add elements*/
	orderedArrayAdd(b, 6); /*Add elements*/
	orderedArrayAdd(b, 3); /*Add elements*/
	orderedArrayAdd(b, 4); /*Add elements*/

	printf("binary searching for 5 (index 2) - %d\n", dyArrayBinarySearch(b,5));

	printf("remove 5\n");

	orderedArrayRemove(b, 5);

	printf("contains search for 5 (return 0) - %d\n", orderedArrayContains(b,5));

	printf("remove 3\n");

	orderedArrayRemove(b, 3);
	printf("contains search for 6 (return 1) - %d\n", orderedArrayContains(b,6));

	printf("hello");
  
	/* delete DynArr */
	deleteDynArr(b);
	
	return 0;
}
