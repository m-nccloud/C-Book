#include <stdio.h>

int main()
{
	int c = getchar();
	if(c <= '9' || c >= '0')
		printf("%d\n%d\n%d\n", c- '0', c, c - 48);
}
