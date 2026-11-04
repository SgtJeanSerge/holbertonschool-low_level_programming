#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: pointer to the string
 *
 * Return: void
 */
void puts2(char *str)
{
	int longueur;
	int i;

	longueur = 0;

	while (str[longueur] != '\0')
	{
		longueur++;
	}

	i = 0;

	while (i < longueur)
	{
		_putchar(str[i]);
		i += 2;
	}
	_putchar('\n');
}
