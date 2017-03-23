//============================================================================
// Name        : deckOfCards.cpp
// Author      : Prashant Mulge
// Version     : 1.0
// Copyright   : @PrashantMulge
// Description : Determining how many rounds it will take to put a deck back into the original order.
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int *initialArr = NULL, *deckArr = NULL, numOfCards = 0, *superInitialArr = NULL;

int comparedecks(int *deckArrPassed)
{
	int i = 0;
	for(i = 1; i <= numOfCards; i++)
	{
		if(superInitialArr[i] != deckArrPassed[i])
			return FALSE;
	}
	return TRUE;
}

int main(int argc, char **argv)
{
	int count = 0, index = 0, start = 1, i = 0, j = 0, ret = 0;
	if(argc >  1)
	{
		numOfCards = atoi(argv[1]);
	}
	else
	{
		printf("Enter the number of cards in a deck: Max to be 52!\n");
		scanf("%d", &numOfCards);
	}
	printf("Number is : %d \n", numOfCards);
	
	initialArr = (int *) malloc ( (sizeof(int) * numOfCards) + 1);
	deckArr = (int *) malloc ( (sizeof(int) * numOfCards) + 1);
	superInitialArr = (int *) malloc ( (sizeof(int) * numOfCards) + 1);
	for(i = 0; i <= numOfCards; i++)
	{
		initialArr[i] = i;
		superInitialArr[i] = i;
	}
	

	while(TRUE)
	{
		i = 0;
		index = 0;
		start = 1;
		while (index < numOfCards)
		{
			i = start;
			while (i <= numOfCards)
			{
				deckArr[numOfCards - index] = initialArr[i];
				i += start * 2;
				index += 1;
			}
			start *= 2;
		}
		ret = comparedecks(deckArr);
		if(ret)
		{
			break;
		}
		printf("\nInitial Array : ");
		for (j = 1; j <= numOfCards; j++)
		{
			printf("%d", initialArr[j]);
		}
		printf("\nFinal Array : ");
		for (j = 1; j <= numOfCards; j++)
		{
			printf("%d", deckArr[j]);
		}
		count += 1;
		free(initialArr);
		initialArr = (int *) malloc (sizeof(int) * numOfCards + 1);
		for (j = 0; j <= numOfCards; j++)
		{
			initialArr[j] = deckArr[j];
		}
		
	}
	printf("\nSuper Intial array : ");
	for (j = 1; j <= numOfCards; j++)
	{
		printf("%d", superInitialArr[j]);
	}
	printf("\nFinal Array : ");
	for (j = 1; j <= numOfCards; j++)
	{
		printf("%d", deckArr[j]);
	}
	printf("\nTotal count = %d\n", count + 1);

	return 0;
}

