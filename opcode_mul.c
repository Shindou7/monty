#include "monty.h"

/**
 * s_mul -  multiplies the top element to the second top element of the stack
 * @head:  head of the linked list
 * @line_number: line_number
 * Return: Nothing
 */
void s_mul(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	flag->next->n = flag->next->n * flag->n;
	*head = flag->next;
	free(flag);
}
