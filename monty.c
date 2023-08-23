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
  * @_param: The error code to manage
  * @line_number: line_number
  * Return: Nothing
  */
int handle_push(stack_t **head, char *_param, unsigned int line_number)
{
	int status_op = check_push_param(_param);

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
  * @line_number: .....
  * @flag: ......
  * Return: nothing
  */
int Exec_function(char *_code, char *_param, unsigned int line_number, int flag)
{
	void (*fd)(stack_t **, unsigned int);

	if (strcmp(_code, "stack") == 0)
		return (METH_STACK);
	else if (strcmp(_code, "queue") == 0)
		return (METH_QUEUE);

	fd = get_opcode_monty(_code);
	if (fd)
	{
		if (strcmp(_code, "push") == 0)
		{
			if (flag != 0 && flag == METH_QUEUE)
				fd = get_opcode_monty("push_queue");
			return handle_push(&head, _param, line_number);
		}
		else
		{
			fd(&head, line_number);
		}
		return (flag);
	}
	_error(ERR_INST, _code, line_number);
	return (ERR_INST);
}

/**
  * main - The Monty Interpreter entry point
  * @argc: The args number
  * @argv: The args passed to the interpreter
  * Return: Always zero

int main(int argn, char *args[])
{
	FILE *fd = NULL;
	size_t line_len = 0;
	unsigned int line_num = 1;
	int readed = 0, op_status = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, *buff = NULL;

	filename = args[1];
	check_args_num(argn);
	fd = open_file(argc, argv);

	while ((readed = getline(&buff, &line_len, fd)) != -1)
	{
		op_code = strtok(buff, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}

			op_param = strtok(NULL, "\t\n ");
			op_status = handle_execution(op_code, op_param, line_num, op_status);

			if (op_status >= 100 && op_status < 300)
			{
				fclose(fd);
				handle_error(op_status, op_code, line_num, buff);
			}
		}

		++line_num;
	}

	frees_stack();
	free(buff);
	fclose(fd);
	return (0);
}
