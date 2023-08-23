#include "monty.h"

/**
  * get_opcode_monty - selects the correct opcode to perform
  * @flag: the opcode
  * Return: pointer to the function that executes 
  */
void (*get_opcode_monty(char *flag))(stack_t **, unsigned int)
{
	instruction_t instruct[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "div", divide },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
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
 *@s2: second string
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
