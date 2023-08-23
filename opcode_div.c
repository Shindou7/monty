#include "monty.h"

/**
 * s_div - divides the second element by the top element of the stack
 * @head: stack head
 * @line_number: line_number
 *
 * Return: Nothing
 */
void s_div(stack_t **head, unsigned int line_number)
{
	stack_t *flag = *head;
	unsigned int  count = 0;

	while (flag != NULL)
	{
		count++;
		flag = flag->next;
	}

	if (count < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

flag = *head;
	if (flag->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	flag->next->n = flag->next->n / flag->n;
	*head = flag->next;
	free(flag);
}
