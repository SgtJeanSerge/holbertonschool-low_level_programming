#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times,
 * each followed by a new line
 */
void print_alphabet_x10(void)
{
	int n;
	char c;

	n = 0;

	while (n <= 9)
	{
		c = 'a';

		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}	
		n++;
		_putchar('\n');
	}
}
