#include "shell.h"

/**
 * handle_builtin - check and execute built-in commands
 * @args: null-terminated array, args[0] is the command
 * @last_status: exit status of the last executed command
 *
 * Return: 1 if a built-in was handled, 0 otherwise
 */
int handle_builtin(char **args, int last_status)
{
	if (strcmp(args[0], "exit") == 0)
		exit(last_status);
	return (0);
}
