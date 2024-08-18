#include <stdio.h>

#define FIRSTBLANK 0
#define SEENBLANK 1

int main()
{
	int c, blankstatus;
	blankstatus = FIRSTBLANK;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			if(blankstatus == FIRSTBLANK)
			{
				blankstatus = SEENBLANK;
				putchar(c);
			}
		}

		else
		{
			blankstatus = FIRSTBLANK;
			putchar(c);	
		}
		
	}
}
