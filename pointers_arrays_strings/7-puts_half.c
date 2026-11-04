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

	longueur = 0;

	while (str[longueur] != '\0')
	{
		longueur++;
	}

	i = (longueur + 1) / 2;

	while (i < longueur)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
