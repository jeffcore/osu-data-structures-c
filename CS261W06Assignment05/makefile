all: prog

prog: AVL.o
	gcc -g -Wall -std=c99 -o prog AVL.o
		
AVL.o: AVL.c AVL.h
	gcc -g -Wall -std=c99 -c AVL.c

clean:	
	rm AVL.o
	rm prog