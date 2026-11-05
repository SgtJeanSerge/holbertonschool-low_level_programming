#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to the string to scan
 * @accept: pointer to the string of accepted bytes
 *
 * Return: number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
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
			i++;
		}
		else
		{
			return (i);
		}
	}
	return (i);
}
