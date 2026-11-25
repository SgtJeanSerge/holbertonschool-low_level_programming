#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: address of the pointer to the first node of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;
	unsigned int i;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	newnode->str = strdup(str);
	if (newnode->str == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->len = i;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}
