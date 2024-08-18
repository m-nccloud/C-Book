#include <stdio.h>
#define MAXSIZE 1000

int main()
{
	int c, max;
	int len = max = 0;
	int arr[MAXSIZE];
	for(int i = 0; i<MAXSIZE; i++)
	{
		arr[i] = 0;
	}
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			arr[len]++;
			if(len > max)
				max = len;
			len = 0;	
		}
		else
		{	
			len++;
		}
	}
	for(int i = 1; i <= max; i++)
	{
		printf("%d:\t", i);
		for(int j = 0; j < arr[i]; j++)
			printf("#");
		printf("\n");
	}
	
}
