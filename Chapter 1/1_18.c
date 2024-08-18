#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copyWithLimit(char to[], char from[], int numChars);

int main()
{
	int len;
	char line[MAXLINE];
	char lineNonTrailing[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > -1)
	{
		if(len == 0) continue;
		int nonWhiteSpaceIndex = -1;
		for (int i = 0; i < len; i++)
		{
			if (line[i] != '\t' && line[i] != ' ')
				nonWhiteSpaceIndex = i;
		}		
		if (nonWhiteSpaceIndex != len - 1 && nonWhiteSpaceIndex != -1) 
		{
			copyWithLimit(lineNonTrailing, line, nonWhiteSpaceIndex + 1);
			printf("%s", lineNonTrailing);
			printf("\n");
		}
		else if (nonWhiteSpaceIndex == len - 1)
			printf("%s\n", line);
	}	
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n' || (c == EOF && i > 0))
		s[i] = '\0';
	else if (c == EOF && i == 0)
		return -1;
	return i;
}


void copyWithLimit(char to[], char from[], int numChars)
{
	for(int i = 0; i <= numChars; i++)
		to[i] = from[i];
	to[numChars] = '\0';
}