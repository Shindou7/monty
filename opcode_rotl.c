#include "monty.h"

/**
  * rotl - rotates the stack to the top
  * @head: The head of the stack
  * @line_number: line_number
  * Return: Nothing
  */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *flag = *head, *new_head = NULL;
	(void) line_number;

	if (flag && flag->next)
	{
		new_head = flag->next;
		while (flag->next != NULL)
		{
			flag = flag->next;
		}
		flag->next = *head;
		*head = new_head;
		new_head->next = NULL;
	}
}
