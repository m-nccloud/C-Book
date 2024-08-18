#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > -1){
		if (len > 5) 
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