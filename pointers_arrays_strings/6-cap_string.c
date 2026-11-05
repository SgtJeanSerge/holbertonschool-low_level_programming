#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 * @s: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	char separateur[] = {' ', '\t', '\n', ';', '.', '!', '?', '"',
		'(', ')', '{', '}', ',', '\0'};
	int i;
	int j;

	if (s[0] == '\0')
		return (s);
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] = s[0] - 32;

	i = 1;

	while (s[i] != '\0')
	{
		j = 0;

		while (separateur[j] != s[i - 1] && separateur[j] != '\0')
		{
			j++;
		}
		if (separateur[j] != '\0' && s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
		i++;
	}
	return (s);
}
