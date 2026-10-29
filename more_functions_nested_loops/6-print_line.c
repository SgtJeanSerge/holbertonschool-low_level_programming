#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character _ should be printed
 *
 * Description: the line ends with a new line.
 * If n is 0 or less, only a new line is printed.
 */
void print_line(int n)
{
	int i;

	i = 0;

	while (i < n)
	{
		_putchar('_');
		i++;
	}
	_putchar('\n');
}
