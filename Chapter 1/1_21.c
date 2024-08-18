#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define DEFAULT_TAB_SPACES 8
int getLine(char line[], int maxline);
void entab(char input[], int size, char output[], int tabs);

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
		entab(line, len, tabsToSpaces, TAB_SPACES);
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

void entab(char input[], int size, char output[], int tabs) 
{
	int spacesSeen = 0;
	int outIndex = 0;
	for(int i = 0; i < size; i++) 
	{
		for(int j = i; j < size && j < i + tabs; j++) 
		{
			output[outIndex] = input[j];
			if(input[j] == ' ')
				spacesSeen++;
			else 
				spacesSeen = 0;
			outIndex = j + tabs - spacesSeen;
			output[outIndex] = 't';
			i += tabs;
		}

	}
	output[size] = '\0';
}