all: prog

prog: bst.o compare.o dynamicArray.o
	gcc -g -Wall -std=c99 -o prog bst.o compare.o dynamicArray.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c
		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c

dynamicArray.o: dynamicArray.c dynamicArray.h 
	gcc -g -Wall -std=c99 -c dynamicArray.c	


clean:	
	rm bst.o
	rm compare.o
	rm prog
