/* CS261- Assignment 1 - Q.5*/
/* Name: Jeff Rix
 * Date: 6/29/13
 * Solution description:  Sticky keyboard program, converts words into sticky caps
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/

	/*loop through elements of array until \0 end of string*/
	int i;
	for(i = 0; word[i] != '\0'; i++)
	{
		/*split element into odd and even*/
		if(i%2 == 0)
		{
			/*check for lower case convert to upper*/
			if (word[i] >= 'a' && word[i] <= 'z')
			{
				word[i] = toUpperCase(word[i]);
			}
		}
		else
		{
			/*check for upper case convert to lower*/
			if (word[i] >= 'A' && word[i] <= 'Z')
			{
				word[i] = toLowerCase(word[i]);
			}
		}
	}
}

int main(){
	int n = 80;
	char word[n];

	/*Read word from the keyboard using scanf*/
	printf("STICKY CAPS WORD CONVERTER:\n");
	printf("Please enter a word:\n");
    scanf("%s", word);

    /*Call sticky*/
    sticky(word);

    /*Print the new word*/
	printf("%s\n", word);
    return 0;
}
