#include "monty.h"

/**
 * pop - remove element a list
 * @head: pointer to first node
 * @line_number: line number
 * Return: Nothing
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *flag = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
  *head = (*head)->next;
	if (*head)
	{
		*head->prev = NULL;
	}
	free(flag);
}
