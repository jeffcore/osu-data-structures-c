/*	main.c: Hash Table Implementation of Concordance
 * 	Jeff Rix
 *  CS261 Assignment 6
 *  8/15/13
 *
 *  */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

int main (int argc, const char * argv[]) {
    const char* filename;
    char *word;
    struct hashMap hashTable;
    int tableSize = 1000;
	clock_t timer;
    
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.

     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input.txt"; /*specify your input text file here*/
    
    printf("opening file: %s\n", filename);
	FILE *file = fopen(filename, "r");
	assert(file != 0);

	timer = clock();
	
    initMap(&hashTable, tableSize);

	while((word = getWord(file)))
	{
		insertMap(&hashTable, word, 1);
	}

    printHashMap(&hashTable);

    fclose(file);

    /*
    printf("size table %d\n", size(&hashTable));
    printf("load table %f\n", tableLoad(&hashTable));
    printf("empty buckets  %d\n", emptyBuckets(&hashTable));
     */

	timer = clock() - timer;
	printf("concordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	freeMap(&hashTable);
	free(word);
    return 0;
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);


	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';

	return word;
}
