#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to convert
 *
 * Return: the converted integer, or 0 if there is no number
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int n;

	i = 0;
	sign = 1;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}

	n = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 - (s[i] - '0');
		i++;
	}
	if (sign == 1)
		n = -n;
	return (n);
}
