all: prog 

hashMap.o: hashMap.c hashMap.h 
	gcc -g -Wall -std=c99 -c hashMap.c
	
spellcheck.o: spellcheck.c hashMap.h
	gcc -g -Wall -std=c99 -c spellcheck.c
		
prog: hashMap.o spellcheck.o
	gcc -g -Wall -std=c99 -o prog hashMap.o  spellcheck.o

clean:
	rm prog
	rm hashMap.o
	rm spellcheck.o
