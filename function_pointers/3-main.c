#include "3-calc.h"

/**
 * main - performs simple operations
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
	int a, b;
	int (*result)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	result = get_op_func(argv[2]);
	if (result == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", result(a, b));
	return (0);
}
