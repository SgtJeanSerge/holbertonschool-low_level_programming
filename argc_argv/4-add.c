#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Add all the numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 1 (Fail) 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i, j, result;

	if (argc == 0)
	{
		printf("0\n");
	}

	result = 0;
	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		result += atoi(argv[i]);
	}
	printf("%d\n", result);
	return (0);
}
