#include <stdio.h>

int main()
{
	int c;
	int nb = 0; 
	int nt = 0; 
	int nl = 0;
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
