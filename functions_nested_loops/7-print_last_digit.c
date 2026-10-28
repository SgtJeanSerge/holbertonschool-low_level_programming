#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to check
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int lastdg;

	lastdg = n % 10;

	if (lastdg < 0)
	{
		lastdg = -lastdg;
	}
	_putchar(lastdg + '0');
	return (lastdg);
}
