#include "shell.h"

/**
 * print_error - print an error message to stderr
 * @prog_name: name of the shell program
 * @cmd: command that was not found
 *
 * Return: void
 */
void print_error(char *prog_name, char *cmd)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog_name, cmd);
}
