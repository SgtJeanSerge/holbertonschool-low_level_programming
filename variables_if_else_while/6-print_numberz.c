#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	char c;

	c = 48;

	while (c <= 57)
	{
		printf("%d", c);
		c++;
	}
	printf("\n");
	return (0);
}
