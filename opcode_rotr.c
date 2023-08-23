#include "monty.h"

/**
  * rotr - mod top of stack y second top stacks
  * @head: head of the linked list
  * @line_number: line_number
  * Return: Nothing
  */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *back_head = NULL;
	(void) line_number;

	if (*head && (*head)->next)
	{
    back_head = *head;

		while (back_head->next != NULL)
			back_head = back_head->next;

		back_head->prev->next = NULL;
		back_head->next = *head;
    (*head)->prev = back_head;
		*head = back_head;
	}
}
