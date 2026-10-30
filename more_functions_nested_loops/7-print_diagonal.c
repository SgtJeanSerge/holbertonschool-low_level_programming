#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character \ should be printed
 *
 * Description: each \ is preceded by as many spaces as its line
 * number (starting at 0), and each line ends with a new line.
 * If n is 0 or less, only a new line is printed.
 */
void print_diagonal(int n)
{
	int row, column;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (column = 0; column < n; column++)
		{
			row = 0;

			while (row < column)
			{
				_putchar(' ');
				row++;
			}
			_putchar('\\');
			_putchar('\n');
		}
	}
}
