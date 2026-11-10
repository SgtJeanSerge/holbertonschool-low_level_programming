#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements in the array
 * @size: size in bytes of each element
 *
 * Return: pointer to the allocated memory, or NULL if nmemb or size
 * is 0 or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *arr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	i = 0;
	arr = malloc(nmemb * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
