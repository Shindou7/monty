#include "monty.h"
/**
 * push - Adds a push int to a stack
 * @head: The head for monty stack
 * @line_number: number of line
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *flag = NULL;

	flag = malloc(sizeof(stack_t));
	if (flag == NULL)
  {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

	flag->n = line_number;
  flag->next = *head;
	flag->prev = NULL;
	
  if (*head)
	{
		(*head)->prev = flag;
	}

	*head = flag;
}
