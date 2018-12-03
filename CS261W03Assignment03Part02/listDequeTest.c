#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque(); 

	addBackCirListDeque(q, (TYPE)1);
	printf("front que 1 - %g\n", frontCirListDeque(q));
	printf("back que 1 - %g\n", backCirListDeque(q));
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("front que 6 - %g\n", frontCirListDeque(q));
	printf("back que 3 - %g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printf("front que 5 - %g\n", frontCirListDeque(q));
	printf("back que 2 - %g\n", backCirListDeque(q));
	printCirListDeque(q);
	reverseCirListDeque(q);
	printCirListDeque(q);
	deleteCirListDeque(q);

	return 0;
}
