all: prog

prog: bst.o
	gcc -g -Wall -std=c99 -o prog bst.o -lm 

bst.o: bst.c bst.h 
	gcc -g -Wall -std=c99 -c bst.c	
		
clean:
	rm bst.o
	rm prog