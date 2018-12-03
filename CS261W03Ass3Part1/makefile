all: prog

prog: linkedList.o bagTest.o
	gcc -g -Wall -std=c99 -o prog linkedList.o bagTest.o -lm 

bagTest.o: bagTest.c linkedList.h 
	gcc -g -Wall -std=c99 -c bagTest.c	

linkedList.o: linkedList.c linkedList.h 
	gcc -g -Wall -std=c99 -c linkedList.c	
		
clean:
	rm linkedList.o
	rm bagTest.o
	rm prog