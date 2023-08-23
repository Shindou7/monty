#include "monty.h"

/**
 * s_pint - print int a top of stack,
 * @head: The head of the stack
 * @line_number: number of line opcode
 * Return: Nothing
 */
void s_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
