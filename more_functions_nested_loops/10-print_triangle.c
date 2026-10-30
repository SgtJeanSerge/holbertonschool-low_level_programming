#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the size of the triangle
 *
 * Description: the triangle is made of size lines, aligned to the right.
 * Line i (starting at 1) contains size - i spaces followed by i #.
 * If size is 0 or less, only a new line is printed.
 */
void print_triangle(int size)
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
			column = 0;

			while (column < size)
			{
				if ((column + row) < size - 1)
				{
					_putchar(' ');
				}
				else
				{
					_putchar('#');
				}
				column++;
			}
			_putchar('\n');
		}
	}
}
