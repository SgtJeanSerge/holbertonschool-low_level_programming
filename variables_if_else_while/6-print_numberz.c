#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	int n;

	n = 0;

	while (n <= 9)
	{
		putchar(n + 48);
		n++;
	}
	putchar('\n');
	return (0);
}
