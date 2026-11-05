#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i;
	int j;
	int num[10] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};
	char lettre[10] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};

	i = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (j <= 9)
		{
			if (s[i] == lettre[j])
			{
				s[i] = num[j];
			}
			j++;
		}
		i++;
	}
	return (s);
}
