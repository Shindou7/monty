#include "monty.h"

/**
  * s_pchar -print the char value of the first element
  * @head: The head of the stack
  * @line_number: The line on which the error occurred
  * Return: Nothing
  */
void s_pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n >= 0 && (*head)->n <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
