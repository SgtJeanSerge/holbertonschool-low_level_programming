#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14,
 * followed by a new line
 */
void more_numbers(void)
{
	int n;
	int t;

	t = 0;

	while (t <= 9)
	{
		n = 0;

		while (n <= 14)
		{
			if (n >= 10)
			{
				_putchar((n / 10) + '0');
			}
			_putchar((n % 10) + '0');
			n++;
		}
		_putchar('\n');
		t++;
	}
}
