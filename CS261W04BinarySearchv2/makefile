all: prog

prog: dynamicArray.o dynamicArrayMain.o
	gcc -g -Wall -std=c99 -o prog dynamicArray.o dynamicArrayMain.o -lm 

dynamicArrayMain.o: dynamicArrayMain.c dynamicArray.h 
	gcc -g -Wall -std=c99 -c dynamicArrayMain.c	

dynamicArray.o: dynamicArray.c dynamicArray.h 
	gcc -g -Wall -std=c99 -c dynamicArray.c	
		
clean:
	rm linkedList.o
	rm prog