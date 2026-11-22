#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the times table to print (from 0 to 15)
 */
void print_times_table(int n)
{
	int i, j, t;

	if (n > 15 || n < 0)
		return;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			t = i * j;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (t >= 100)
			{
				_putchar((t / 100) + '0');
				_putchar(((t / 10) % 10) + '0');
				_putchar((t % 10) + '0');
			}
			else if (t >= 10)
			{
				_putchar(' ');
				_putchar((t / 10) + '0');
				_putchar((t % 10) + '0');
			}
			else
			{
				if (j != 0)
				{
					_putchar(' ');
					_putchar(' ');
				}
				_putchar(t + '0');
			}
		}
		_putchar('\n');
	}
}
