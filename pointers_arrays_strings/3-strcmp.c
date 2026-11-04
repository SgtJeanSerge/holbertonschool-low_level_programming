#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: 0 if s1 and s2 are equal, a negative value if s1 is less
 * than s2, a positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
