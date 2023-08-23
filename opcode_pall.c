#include "monty.h"

/**
 * pall - Prints all the values on the stack
 *
 * @head: head of the linked list
 * @line_number: line numbers
 * Return: no return
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *montty;
	(void)line_number;

	montty = *head;

	while (montty)
	{
		printf("%d\n", montty->n);
		montty = montty->next;
	}
}
