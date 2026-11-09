#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars and initializes it with a char
 * @size: number of chars in the array
 * @c: the char to fill the array with
 *
 * Return: pointer to the array, or NULL if size is 0 or if malloc fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *ar;

	i = 0;

	if (size == 0)
	{
		return (NULL);
	}

	ar = malloc(size * sizeof(char));
	while (i < size)
	{
		if (ar == NULL)
		{
			return (NULL);
		}
		else
		{
			ar[i] = c;
			i++;
		}
	}
	return (ar);
}
