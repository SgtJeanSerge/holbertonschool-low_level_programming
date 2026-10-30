#include "main.h"

/**
 * print_square - prints a square, followed by a new line
 * @size: the size of the square
 *
 * Description: the square is made of size lines of size #
 * characters, each line ending with a new line.
 * If size is 0 or less, only a new line is printed.
 */
void print_square(int size)
{ 
	int column, row;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (row = 0; row < size; row++)
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
