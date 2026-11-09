#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: the string to duplicate
 *
 * Return: pointer to the new string, or NULL if str is NULL
 * or if malloc fails
 */
char *_strdup(char *str)
{
	int i;
	int j;
	char *ar;

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	j = 0;
	ar = malloc((i + 1) * sizeof(char));
	if (ar == NULL)
	{
		return (NULL);
	}
	while (j < i)
	{
		ar[j] = str[j];
		j++;
	}
	ar[j] = '\0';
	return (ar);
}
