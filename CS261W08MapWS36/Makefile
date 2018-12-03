all: prog1 

prog1: dynamicArray.o dyarraydict.o
	gcc -g -Wall -std=c99 -o prog1 dynamicArray.o dyarraydict.o 
	

dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -g -Wall -std=c99 -c dynamicArray.c
	
dyarraydict.o: dyarraydict.c dyarraydict.h
	gcc -g -Wall -std=c99 -c dyarraydict.c

clean:	
	rm dynamicArray.o
	dyarraydict.o
	rm prog1
	
