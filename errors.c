#include "shell.h"

/**
 * print_error - print an error message to stderr
 * @prog_name: name of the shell program
 * @cmd: command that failed (unused in Task 2, kept for future tasks)
 *
 * Return: void
 */
void print_error(char *prog_name, char *cmd)
{
	(void)cmd;
	perror(prog_name);
}
