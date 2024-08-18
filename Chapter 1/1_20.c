#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define DEFAULT_TAB_SPACES 7
int getLine(char line[], int maxline);
void detab(char input[], int size, char output[], int tabs);

int main(int argc, char *argv[])
{							    					
	int len;
	char line[MAXLINE];
	char validTabOptionSelected = 0;
	int inputVal;

	if(argc == 2)
	{
		inputVal = atoi(argv[1]);
		if(inputVal != 0)
			validTabOptionSelected = 1;
		else 
		{
			printf("Invalid input\n");
			return -1;
		}
	}
	else if(argc > 2) 
	{
		printf("Too many arguments\n");
		return -1;
	}
	const int TAB_SPACES = validTabOptionSelected ? inputVal : DEFAULT_TAB_SPACES;

	while ((len = getLine(line, MAXLINE)) > -1)
	{
		char tabsToSpaces[MAXLINE];
		detab(line, len, tabsToSpaces, TAB_SPACES);
		printf("%s\n", tabsToSpaces);
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

void detab(char input[], int size, char output[], int tabs) 
{
	int offset = 0;
	int currLen = 0;
	for(int i = 0; i < size; i++)
	{
		if(input[i] != '\t')
		{
			output[i + offset] = input[i];
			currLen++;
		}
		else 
		{
			int diff = abs(tabs - currLen);
			if(diff == 0) diff = tabs;
			for(int j = i + offset; j <= i + offset + diff; j++)
				output[j] = ' ';
			offset += diff;
			currLen = 0;
		}
	}
	output[size + offset] = '\0';
}