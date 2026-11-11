#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max
 * @min: first value of the array (included)
 * @max: last value of the array (included)
 *
 * Return: pointer to the newly created array, or NULL if min > max
 * or if malloc fails
 */
int *array_range(int min, int max)
{
	int i;
	int *arr;

	if (min > max)
	{
		return (NULL);
	}

	i = 0;
	arr = malloc((max - min + 1) * sizeof(int));
	if (arr == NULL)
	{
		return (NULL);
	}
	while (min <= max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
