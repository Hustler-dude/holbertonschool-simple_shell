#include "shell.h"

/**
 * main - entry point of the simple shell
 * @ac: argument count (unused)
 * @av: argument vector, av[0] is the shell program name
 * @env: environment variables array
 *
 * Return: exit status of the last executed command
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t nread;
	int status = 0;

	(void)ac;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		if (line[0] == '\0')
			continue;
		args = parse_line(line);
		if (!args || !args[0])
		{
			free(args);
			continue;
		}
		if (handle_builtin(args, status))
		{
			free(args);
			continue;
		}
		status = execute(args, av[0], env);
		free(args);
	}
	return (status);
}
