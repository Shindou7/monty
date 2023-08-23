#include "monty.h"

/**
 * mod - computes the rest of the division of the second
 * @head: stack head
 * @line_number: line_number
 * Return: Nothing
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *flag = *head;
	unsigned int count = 0;

	while (flag != NULL)
	{
		count++;
		flag = flag->next;
	}
	if (count < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	flag = *head;
	if (flag->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	flag->next->n = flag->next->n % flag->n;
	*head = flag->next;
	free(flag);
}
