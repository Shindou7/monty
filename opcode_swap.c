#include "monty.h"

/**
 * swap - adds the top two elements of the stack
 * @head: pointer to lists for monty stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int line_number)
{
	unsigned int  temp = 0, count = 0;

	stack_t *flag = *head;

	while (flag != NULL)
	{
		++count;
		flag = flag->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*head)
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
}
