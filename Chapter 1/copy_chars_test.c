#include <stdio.h>

void copy(char from[], char to[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		i++;
}

int main()
{
	char s1[10] = "hello!123";
	char s2[10];
	copy(s1, s2);
	printf("%s\n%s\n", s1, s2);
}
