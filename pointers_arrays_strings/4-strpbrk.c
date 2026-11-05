#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: pointer to the string to search
 * @accept: pointer to the string of bytes to look for
 *
 * Return: pointer to the first byte in s that matches one of the bytes
 * in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
	int j;

	i = 0;

	while (s[i] != '\0')
	{
		j = 0;

		while (s[i] != accept[j] && accept[j] != '\0')
		{
			j++;
		}
		if (s[i] == accept[j])
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
