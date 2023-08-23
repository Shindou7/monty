#include "monty.h"

/**
 * sub - subtracts the top element to the second top element of_the_stack
 * @head: The head of the stack
 * @line_number: line_number
 * Return: Nothing
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *flag = *head;
	unsigned int count = 0;

	while (flag != NULL)
	{
		count++;
		flag = flag->next;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	flag = *head;
	flag->next->n = flag->next->n - flag->n;
	*head = flag->next;
	free(flag);
}
