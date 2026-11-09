#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated space
 * @s1: the first string (treated as empty if NULL)
 * @s2: the second string (treated as empty if NULL)
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	char *ar;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = 0;
	while (s1[i] != '\0')
		i++;

	j = 0;
	while (s2[j] != '\0')
		j++;

	k = 0;
	ar = malloc((i + j + 1) * sizeof(char));
	if (ar == NULL)
		return (NULL);

	i = 0;
	while (s1[i] != '\0')
	{
		ar[k] = s1[i];
		k++;
		i++;
	}

	j = 0;
	while (s2[j] != '\0')
	{
		ar[k] = s2[j];
		k++;
		j++;
	}
	ar[k] = '\0';
	return (ar);
}
