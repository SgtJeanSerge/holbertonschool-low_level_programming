#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog with copies of name and owner
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *p;
	char *n;
	char *o;
	int i;
	int j;
	/* allocating memory for struct */
	p = malloc(sizeof(dog_t));
	if (p == NULL)
		return (NULL);
	/* count/allocate/add character from name */
	for (i = 0; name[i] != '\0'; i++)
		;
	n = malloc(i * sizeof(char) + 1);
	if (n == NULL)
	{
		free(p);
		return (NULL);
	}
	for (j = 0; j <= i; j++)
		n[j] = name[j];
	/* count/allocate/add character from ownner */
	for (i = 0; owner[i] != '\0'; i++)
		;
	o = malloc(i * sizeof(char) + 1);
	if (o == NULL)
	{
		free(n);
		free(p);
		return (NULL);
	}
	for (j = 0; j <= i; j++)
		o[j] = owner[j];
	p->name = n;
	p->age = age;
	p->owner = o;
	return (p);
}
