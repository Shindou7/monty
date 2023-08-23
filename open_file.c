#include "monty.h"
/**
 * open_file - Opens a file to interpret the commands within
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */

FILE *open_file(int argc, char *argv[])
{
	FILE *filename;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = fopen(argv[1], "r");

	if (filename == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (filename);
}

/**
 * _push_param - O_push_param
 * @_param: _param
 * Return: file struct
 */
int _push_param(char *_param)
{
    if (_param == NULL || !_digits(_param))
        return (ERR_PUSH);

    return (VALID_PARM);
}

/**
 * _digits - _digits ...
 * @str: string 
 * Return: file struct
 */
int _digits(char *str)
{
    while (*str != '\0')
    {
        if (!isdigit(*str) && str[0] != '-')
            return (0);

        ++str;
    }
    return (1);
}


/**
 * _queues - _queues
 * @head: argument count
 * @value: argument vector
 * Return: file struct
 */
void _queues(stack_t **head, unsigned int value)
{
    stack_t *new_elem = malloc(sizeof(stack_t));
    if (new_elem == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_elem->n = value;
    new_elem->next = NULL;

    if (*head)
    {
        stack_t *flag = *head;
        while (flag->next != NULL)
            flag = flag->next;
        new_elem->prev = flag;
        flag->next = new_elem;
    }
    else
    {
        new_elem->prev = NULL;
        *head = new_elem;
    }
}
