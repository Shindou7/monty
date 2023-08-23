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
