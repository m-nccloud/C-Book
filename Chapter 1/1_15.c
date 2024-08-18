#include <stdio.h>

int fahrToCels(int fahr);

int main()
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = fahrToCels(fahr);
		printf("%d\t%d\n", fahr, celsius);
		fahr += step;
	}	

}

int fahrToCels(int fahr)
{
	return (5 * (fahr - 32) / 9);
}
