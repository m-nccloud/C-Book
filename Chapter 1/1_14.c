#include <stdio.h>

int main()
{
	int c;
	int chars[26];
	for(int i = 0; i < 26; i++)
		chars[i] = 0;

	while((c = getchar()) != EOF)
	{
		if(c != ' ' && c != '\t' && c != '\n')
		{
			if((c - 97) < 0)
				chars[c - 65]++;
			else
				chars[c - 97]++;	
		}		
	}
	for(int i = 0; i < 26; i++)
	{
		printf("%c| ", i + 97);
		for(int j = 0; j < chars[i]; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}
