all: prog

prog: bst.o main.c
	gcc -g -Wall -std=c99 -o prog bst.o main.c


		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c

clean:	
	rm bst.o
	rm compare.o
	rm prog
