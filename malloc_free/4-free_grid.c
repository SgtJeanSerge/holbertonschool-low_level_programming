#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: pointer to the 2 dimensional grid to free
 * @height: number of rows of the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	i = 0;

	if (grid == NULL)
	{
		return;
	}

	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
