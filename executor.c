#include "shell.h"

/**
 * execute - find, fork and execve the given command
 * @args: null-terminated array, args[0] is the command
 * @prog_name: shell program name used in error messages
 * @env: environment variables passed to execve
 *
 * Return: exit status of child, 127 if not found, 1 on fork error
 */
int execute(char **args, char *prog_name, char **env)
{
	pid_t pid;
	int status;
	char *path;

	path = find_in_path(args[0], env);
	if (!path)
	{
		print_error(prog_name, args[0]);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		if (path != args[0])
			free(path);
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		execve(path, args, env);
		print_error(prog_name, args[0]);
		exit(127);
	}
	wait(&status);
	if (path != args[0])
		free(path);
	return (WEXITSTATUS(status));
}
