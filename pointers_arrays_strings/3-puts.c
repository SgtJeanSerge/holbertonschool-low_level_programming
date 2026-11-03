#include "main.h"

/**
 * _puts - point a string followed by a new line
 * @str: pointer to the string
 *
 * Return: The string
 */
void _puts(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	putchar('\n');
}
