#include <stdio.h>

/**
 * main - prints the numbers from 1 to 100, replacing multiples
 * of 3 by Fizz, multiples of 5 by Buzz, and multiples of both by FizzBuzz
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 1; n <= 100; n++)
	{
		if ((n % 5 == 0) && (n % 3 == 0))
		{
			printf("FizzBuzz");
		}
		else if (n % 5 == 0)
		{
			printf("Buzz");
		}
		else if (n % 3 == 0)
		{
			printf("Fizz");
		}
		else
		{
			printf("%d", n);
		}
		if (n != 100)
		{
		printf(" ");
		}
	}
	printf("\n");
	return (0);
}
