#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: the array of integers
 * @size: the number of elements in the array
 * @cmp: pointer to the function used to compare values
 *
 * Return: index of the first element for which cmp does not return 0,
 * or -1 if no element matches or if size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int result;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		result = cmp(array[i]);
		if (result != 0)
			return (i);
	}
	return (-1);
}
