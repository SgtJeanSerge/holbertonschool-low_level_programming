#include "main.h"

/**
 * string_toupper - fonction change lowercase to upper
 * @s: pointer to the string with caracteres to change
 *
 * Return: pointer to the modified string
 */
char *string_toupper(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (s);
}
