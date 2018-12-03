/*
 * Hello.c
 *
 *  Created on: Jun 22, 2013
 *      Author: Jeff Rix
 *      This program sums up numbers in an array
 */
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
/*
	int numArray[] = {1,2,3,4,5,6,7,8,9,10};
	int sumNumbers = 0;
	printf("Add the following Numbers from this array:\n");

	int i;
	for (i = 0; i < N; ++i)
	{
		printf("%d\n", numArray[i]);
		sumNumbers += numArray[i];
	}
	printf("The sum is:  %d ", sumNumbers);

	int *data = malloc(sizeof(int)*10);


	for(i = 0;i < 10;i++)
	{
		data[i] = i;
	}

	for(i = 0;i < 10;i++)
	{
		printf("%d\n",data[i]);
	}

	int *dataTemp = malloc(sizeof(int)*20);

	for(i = 0;i < 10; i++)
	{
	  dataTemp[i] = data[i] + 1;
	}
	for(i = 0;i < 10;i++)
	{
		printf("%d\n",dataTemp[i]);
	}

	printf("%p\n", data);
	printf("%p\n", dataTemp);
	printf("%d\n", data);
	printf("%d\n", dataTemp);
	data = dataTemp;
	//free(dataTemp);
	printf("data pointer after %p\n", data);

	printf("data decmial%d\n", data);
	printf("----");

	for(i = 0;i < 10;i++)
	{
		printf("%d\n",data[i]);
	}
*/
	 int a[5] = {5, 1, 15, 20, 25};
	 int i, j, m = 0;
	 i = ++a[1];
	 j = a[1]++;
	 //a[1]++;
	 m = a[i++];
	 printf("element 1: %d\n", a[1]);
	 printf("%d, %d, %d\n", i, j, m);

	 int theNum, total;    total = 1;    theNum = 5;
	 while (theNum > 1) {     total *= --theNum;    }
	 printf ("%d", total);


	return 0;
}

