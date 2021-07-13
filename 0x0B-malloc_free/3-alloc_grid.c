#include <stdlib.h>

/**
 * alloc_grid - Create a 2 dimensionals array
 * @width: Width of grid, aka # of columns
 * @height: Height of grid, aka # of rows
 *
 * Return: Pointer to 2D array, NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int a, b;

	a = 0;
	if (width <= 0 || height <= 0)
		return (NULL);
	grid = malloc(height * sizeof(*grid));
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}
	while (a < height)
	{
		grid[a] = malloc(width * sizeof(**grid));
		if (grid[a] == NULL)
		{
			a--;
			while (a >= 0)
			{
				free(grid[a]);
				a--;
			}
			free(grid);
			return (NULL);
		}
		b = 0;
		while (b < width)
		{
			grid[a][b] = 0;
			b++;
		}
		a++;
	}
	a = 0;
	return (grid);
}
