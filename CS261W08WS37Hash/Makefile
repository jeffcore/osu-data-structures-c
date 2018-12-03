all: prog1 

prog1: hashTable.o
	gcc -g -Wall -std=c99 -o prog hashTable.o 
	
hashTable.o: hashTable.c hashTable.h
	gcc -g -Wall -std=c99 -c hashTable.c

clean:	
	rm hashTable.o	
	rm prog1
	
