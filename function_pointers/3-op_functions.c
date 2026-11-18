#include "3-calc.h"

/**
 * op_add - adds two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the sum of a and b
 */
int op_add(int a, int b)
{
	int result;

	result = a + b;

	return (result);
}

/**
 * op_sub - subtracts two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the difference of a and b
 */
int op_sub(int a, int b)
{
	int result;

	result = a - b;

	return (result);
}

/**
 * op_mul - multiplies two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the product of a and b
 */
int op_mul(int a, int b)
{
	int result;

	result = a * b;

	return (result);
}

/**
 * op_div - divides two integers
 * @a: the dividend
 * @b: the divisor
 *
 * Return: the result of the division of a by b
 */
int op_div(int a, int b)
{
	int result;

	result = (a * 1.0) / b;

	return (result);
}

/**
 * op_mod - computes the remainder of a division
 * @a: the dividend
 * @b: the divisor
 *
 * Return: the remainder of the division of a by b
 */
int op_mod(int a, int b)
{
	int result;

	result = a % b;

	return (result);
}

