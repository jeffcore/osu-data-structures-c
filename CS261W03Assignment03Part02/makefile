all: prog

prog: cirListDeque.o listDequeTest.o
	gcc -Wall -std=c99 -o prog cirListDeque.o listDequeTest.o

listDequeTest.o: listDequeTest.c cirListDeque.h
	gcc -g -Wall -std=c99 -c listDequeTest.c	

cirListDeque.o: cirListDeque.c cirListDeque.h 
	gcc -Wall -std=c99 -c cirListDeque.c	
		
clean:
	rm cirListDeque.o

cleanall: clean
	rm prog
