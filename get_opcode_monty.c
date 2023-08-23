#include "monty.h"

/**
  * get_opcode_monty - selects the correct opcode to perform
  * @flag: the opcode
  * Return: pointer to the function that executes
  */
void (*get_opcode_monty(char *flag))(stack_t **, unsigned int)
{
	instruction_t instruct[] = {
		{ "push", s_push },
		{ "pall", s_pall },
		{ "pint", s_pint },
		{ "push_queue", s_queues },
		{ "pop", s_pop },
		{ "swap", s_swap },
		{ "add", s_add },
		{ "nop", s_nop },
		{ "sub", s_sub },
		{ "div", s_div },
		{ "mul", s_mul },
		{ "mod", s_mod },
		{ "pchar", s_pchar },
		{ "pstr", s_pstr },
		{ "rotl", s_rotl },
		{ "rotr", s_rotr },
		{ NULL, NULL }
	};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (_strcmp(flag, instruct[i].opcode) == 0)
			return (instruct[i].f);

		++i;
	}

	return (NULL);
}


/**
 * _strcmp - check the code
 *@str1: first string
 *@str2: second string
 * Return: Always 0.
 */

int _strcmp(char *str1, char *str2)
{
	int a = 0;
	int b = 0;

	while (b == 0)
	{
		if ((*(str1 + a) == '\0') && (*(str2 + a) == '\0'))
			break;
		b = *(str1 + a) - *(str2 + a);
		a++;
	}
	return (b);
}
