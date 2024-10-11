#include <stdio.h>
#define IN 1
#define OUT 0

int isBlank(int c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return 1;
	return -1;
}

int main()
{
    int state = IN;
    int c;
    while((c = getchar()) != EOF)
    {
    	if(state == OUT && isBlank(c) == -1)
	{
		state = IN;
		putchar(c);
	}
	else if(state == IN && isBlank(c) == -1)
	{
		putchar(c);
	}
	else if(state == IN && isBlank(c) == 1)
	{
		state = OUT;
		putchar('\n');
	}
    	else
    		printf("\n");
	}
}
