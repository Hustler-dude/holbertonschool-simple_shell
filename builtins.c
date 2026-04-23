#include "shell.h"

/**
 * handle_builtin - check and execute built-in commands
 * @args: null-terminated array, args[0] is the command
 * @last_status: exit status of the last executed command
 * @env: environment variables array
 *
 * Return: 2 if exit requested, 1 if built-in handled, 0 otherwise
 */
int handle_builtin(char **args, int last_status, char **env)
{
	int i;

	(void)last_status;
	if (strcmp(args[0], "exit") == 0)
		return (2);
	if (strcmp(args[0], "env") == 0)
	{
		i = 0;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
		return (1);
	}
	return (0);
}
