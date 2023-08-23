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

int handle_push(stack_t **stack, char *op_param, unsigned int line_number)
{
    int status_op = check_push_param(op_param);
    if (status_op == ERR_PUSH)
    {
        _error(ERR_PUSH, NULL, line_number);
        return ERR_PUSH;
    }

    push(stack, atoi(op_param));
    return VALID_PARM;
}


/**
  * Exec_function - Exec_function
  * @_code: ....
  * @_param: .....
  * @line_number: .....
  * @flag: ......
  *
  * Return: 0 if the operation was executed correctly or errcode if is invalid
  */

int Exec_function(char *_code, char *_param, unsigned int line_number, int flag)
{
    void (*fd)(stack_t **, unsigned int);

    if (strcmp(_code, "stack") == 0)
        return METH_STACK;
    else if (strcmp(_code, "queue") == 0)
        return METH_QUEUE;

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

int main(int argc, char *argv[])
{
    void (*f)(stack_t **stack, unsigned int line_number);
    FILE *fd;
    size_t size = 256;
    ssize_t nlines = 0;
    char *lines[2] = {NULL, NULL};
    stack_t *head = NULL;
    char *buffer = NULL;
    unsigned int cont = 1;

    fd = check_input(argc, argv);

    nlines = getline(&buffer, &size, fd);
    while (nlines != -1)
    {
        lines[0] = _strtoky(buffer, " \t\n");
        if (lines[0] && lines[0][0] != '#')
        {
            f = get_opcodes(lines[0]);
            if (!f)
            {
                dprintf(2, "L%u: ", cont);
                dprintf(2, "unknown instruction %s\n", lines[0]);
                free(buffer);
                fclose(fd);
                exit(EXIT_FAILURE);
            }
            vglo.arg = _strtoky(NULL, " \t\n");
            f(&head, cont);
        }
        nlines = getline(&buffer, &size, fd);
        cont++;
    }

    free(buffer);
    fclose(fd);

    free_dlistint(head);

    return (0);
}
