#include "3-calc.h"

/**
 * get_op_func - selects the function matching the given operator
 * @s: the operator passed as argument to the program
 *
 * Return: pointer to the function that corresponds to the operator,
 * or NULL if the operator does not match any of the expected ones
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};
	int i;

	i = 0;

	while (ops[i].op != NULL)
	{
		if (ops[i].op[0] == *s && *(s + 1) == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
