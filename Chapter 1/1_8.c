#include <stdio.h>

int main()
{
	int c, nb, nt, nl;
	while((c=getchar()) != EOF)
	{
		if(c == ' ')
			nb++;
		else if(c == '\t')
			nt++;
		else if(c == '\n')
			nl++;
	}
	printf("\n number of blanks: %d\n number of tabs: %d\n number of newlines: %d\n", nb, nt, nl); 
}
