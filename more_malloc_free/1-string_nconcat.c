#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 and the first n bytes of s2
 * @s1: the first string (treated as empty if NULL)
 * @s2: the second string (treated as empty if NULL)
 * @n: maximum number of bytes of s2 to concatenate
 *
 * Return: pointer to the newly allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;
	char *arr;

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

	arr = malloc((i + j) * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	k = 0;
	while (s1[k] != '\0')
	{
		arr[k] = s1[k];
		k++;
	}
	if (j <= n)
	{
		j = 0;
		while (s2[j] != '\0')
		{
			arr[k] = s2[j];
			k++;
			j++;
		}
		arr[k] = '\0';
		return (arr);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			arr[k] = s2[i];
			k++;
			i++;
		}
		arr[k] = '\0';
		return (arr);
	}
}
