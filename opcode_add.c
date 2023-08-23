#include "monty.h"

/**
 * add - Adds  the stack
 * @head: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void add(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	flag->next->n = flag->n + flag->next->n;
	*head = flag->next;
	free(flag);
}
