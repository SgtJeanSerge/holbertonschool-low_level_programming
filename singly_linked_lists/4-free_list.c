#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the first node of the list
 *
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *adress;

	while (head != NULL)
	{
		adress = head->next;
		free(head->str);
		free(head);
		head = adress;
	}
}
