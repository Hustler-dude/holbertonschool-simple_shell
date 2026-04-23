#include "shell.h"

/**
 * execute - fork and execve the given command
 * @args: null-terminated array, args[0] is the full command path
 * @prog_name: shell program name used in error messages
 * @env: environment variables passed to execve
 *
 * Return: exit status of child, 127 if not found, 1 on fork error
 */
int execute(char **args, char *prog_name, char **env)
{
	pid_t pid;
	int status;

	if (access(args[0], X_OK) != 0)
	{
		print_error(prog_name, args[0]);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			print_error(prog_name, args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		return (WEXITSTATUS(status));
	}
	return (0);
}
