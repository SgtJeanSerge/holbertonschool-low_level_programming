#include "main.h"

/**
 * puts_half - prints every other character of a string
 * @str: pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int longueur;
	int i;
	int n;

	longueur = 0;

	while (str[longueur] != '\0')
	{
		longueur++;
	}

	i = 0;
	n = longueur / 2;

	while (n < longueur)
	{
		_putchar(str[n]);
		n++;
	}
	_putchar('\n');
}
