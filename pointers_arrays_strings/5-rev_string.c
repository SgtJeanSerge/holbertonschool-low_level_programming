#include "main.h"

/**
 * rev_string - reverse a string and store it in memory
 * @s: pointer to the string to reverse and store
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i;
	int irev;
	char temp;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	irev = i - 1;
	i = 0;

	while (i < irev)
	{
		temp = s[i];
		s[i] = s[irev];
		s[irev] = temp;
		irev--;
		i++;
	}
}
