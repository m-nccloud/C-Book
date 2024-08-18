#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[]);

int main()
{
	int len;
	char line[MAXLINE];
	char lineNonTrailing[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > -1)
	{
		reverse(line);
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

void reverse(char s[])
{
	int len = 0;
	while(s[len] != '\0')
		len++;
	for(int i = 0; i < len/2; i++)
	{
		char tmp = s[i];	
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}

}
