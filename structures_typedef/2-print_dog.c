#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Print the members of a struct dog
 * @d: Pointer to the struct dog to print
 *
 * Description: If d is NULL, nothing is printed.
 * If name or owner is NULL, (nil) is printed instead.
 *
 * Return: Nothing (void)
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);
	printf("Age: %.6f\n", d->age);
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
