#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i;
	int j;
	int t;

	for (i = 0; i <= 9; i++)
	{
		j = 0;

		while (j <= 9)
		{
			t = i * j;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (t >= 10)
			{
				_putchar((t / 10) + '0');
				_putchar((t % 10) + '0');
			}
			else
			{
				if (j != 0)
					_putchar(' ');
				_putchar(t + '0');
			}
			j++;
		}
		_putchar('\n');
	}
}
