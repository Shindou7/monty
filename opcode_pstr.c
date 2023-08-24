#include "monty.h"

/**
  * s_pstr - prints the string starting
  * @head: The head of the stack
  * @line_number: The line on which the error occurred
  * Return: Nothing
  */
void s_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *flag;
	(void)line_number;

	flag = *head;

	while (flag && flag->n > 0 && flag->n < 128)
	{
		printf("%c", flag->n);
		flag = flag->next;
	}

	printf("\n");
}
