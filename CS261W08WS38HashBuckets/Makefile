all: prog 

prog: hashTableBuckets.o
	gcc -g -Wall -std=c99 -o prog hashTableBuckets.o 
	
hashTableBuckets.o: hashTableBuckets.c hashTableBuckets.h
	gcc -g -Wall -std=c99 -c hashTableBuckets.c

clean:	
	rm hashTableBuckets.o	
	rm prog
	
