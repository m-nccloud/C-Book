#include <stdio.h>
#define MAXLINE 11

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > -1)
		if (len > max) 
		{
			max = len;
			copy(longest, line);
		}
	if (max > 0)
	{
		for(int i = 0; i < 50; i++)
			printf("*");
		if(max == 1)
			printf("\nLongest Line: '%s', %d character", longest, max);
		else if(max <= MAXLINE && max > 1)
			printf("\nLongest Line: '%s', %d characters", longest, max);
		else 
			printf("\nLongest Line: '%s...', %d characters", longest, max);
		int diff;
		if((diff = max + 1 - MAXLINE) > 0)
			printf(", %d omitted", diff);
		printf("\n");
	}
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = '\0';
	}
	else if(c == EOF)
		return -1;
	else if(i == lim - 1)  
	{
		int overflow = i;
		int c2;
		while((c2 = getchar()) != EOF && c2 != '\n')
			overflow++;
		s[i] = '\0';
		return overflow;
	}
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
