#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: number of columns of the grid
 * @height: number of rows of the grid
 *
 * Return: pointer to the grid with every element set to 0,
 * or NULL if width or height is 0 or negative, or on failure
 */
int **alloc_grid(int width, int height)
{
	int i;
	int j;
	int **ar;

	i = 0;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	ar = malloc(height * sizeof(int *));
	if (ar == NULL)
	{
		return (NULL);
	}
	while (i < height)
	{
		j = 0;
		ar[i] = malloc(width * sizeof(int));

		if (ar[i] == NULL)
		{
			while (i >= 0)
			{
				free(ar[i]);
				i--;
			}
			free(ar);
			return (NULL);
		}
		while (j < width)
		{
			ar[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ar);
}
