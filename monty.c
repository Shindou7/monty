#include "monty.h"

/**
 * _error - Error
 * @err0: The error code to manage
 * @message: message error
 * @line_number: line_number
 * Return: Nothing
 */
void _error(int err0, char *message, unsigned int line_number)
{
	switch (err0)
	{
		case ERR_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, message);
			break;
		case ERR_PUSH:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		default:
			break;
	}
}

/**
  * handle_push - Error
  * @head: head monty
  * @_param: The error code to manage
  * @line_number: line_number
  * Return: Nothing
  */
int handle_push(stack_t **head, char *_param, unsigned int line_number)
{
	int status_op = _push_param(_param);

	if (status_op == ERR_PUSH)
	{
		_error(ERR_PUSH, NULL, line_number);
		return (ERR_PUSH);
	}
	push(head, atoi(_param));
	return (VALID_PARM);
}


/**
  * Exec_function - Exec_function
  * @_code: ....
  * @_param: .....
  * @_number: .....
  * @flag: ......
  * Return: nothing
  */
int Exec_function(char *_code, char *_param, unsigned int _number, int flag)
{
	void (*fd)(stack_t **, unsigned int);

	if (strcmp(_code, "stack") == 0)
		return (_STACK);
	else if (strcmp(_code, "queue") == 0)
		return (_QUEUE);

	fd = get_opcode_monty(_code);
	if (fd)
	{
		if (strcmp(_code, "push") == 0)
		{
			if (flag != 0 && flag == _QUEUE)
				fd = get_opcode_monty("push_queue");
			return (handle_push(&head, _param, _number));
		}
		else
		{
			fd(&head, _number);
		}
		return (flag);
	}
	_error(ERR_INST, _code, _number);
	return (ERR_INST);
}
/**
 * free_stack - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}


/**
  * main - The Monty
  * @argc: The args number
  * @argv: The args passed to the interpreter
  * Return: Always zero
*/
int main(int argc, char *argv[])
{
	FILE *fd = NULL;
	unsigned int line_number = 1;
	size_t line_lenght = 0;
	int rd = 0, staty = 0;
	char *filename = NULL, *_code = NULL, *_param = NULL, *buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = args[1];
	fd = open_file(argc, argv);
	while ((rd = getline(&buffer, &line_lenght, fd)) != -1)
	{
		_code = strtok(buff, "\t\n ");
		if (_code && _code[0] != '#')
		{
			_param = strtok(NULL, "\t\n ");
			staty = Exec_function(_code, _param, line_number, staty);

			if (staty >= 100 && staty < 300)
			{
				fclose(fd);
				free(buffer);
				frees_stack(head);
				return (staty);
			}
		}
		++line_number;
	}
	free(buffer);
	fclose(fd);
	frees_stack(head);
	return (0);
}
