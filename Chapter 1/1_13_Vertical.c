#include <stdio.h>
#define MAXSIZE 1000
#define SPACE 0
#define NSPACE 1

int main()
{
	int c, max, maxFreq, prevSpace;
	prevSpace = NSPACE;
	int len = max = maxFreq = 0;
	int arr[MAXSIZE];
	for(int i = 0; i<MAXSIZE; i++)
	{
		arr[i] = 0;
	}

	//building lengths array
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if(prevSpace == NSPACE)
			{
				arr[len]++;
				prevSpace = SPACE;
			}
			if(arr[len] > maxFreq)
				maxFreq = arr[len];
			if(len > max)
				max = len;
			len = 0;	
		}
		else
		{	
			prevSpace = NSPACE;
			len++;
		}
	}

	//main logic
	for(int i = maxFreq; i > 0; i--)
	{
		printf("%2d|", i);
		for(int j = 1; j <= max; j++)
		{
			//printf("i:%d j:%d\n", i, arr[j]);
			if((arr[j] - i) >= 0)
				printf(" #  ");
			else
				printf("    ")	;
		}
		printf("\n");
	}
	printf("   ");
	//printing border
	for(int k = 1; k <= max; k++)
	{
		printf(" _  ");
	}
	printf("\n   ");
	for(int k = 1; k <= max; k++)
	{
		printf("%2d  ", k);
	}
	printf("\nmaxFreq: %d\nmax: %d\n", maxFreq, max);
	for(int i = 0; i<=max; i++) printf("%d ", arr[i]);
	printf("\n");
}	
