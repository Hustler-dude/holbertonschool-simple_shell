#include "shell.h"

/**
 * prompt_and_read - display prompt and read one line from stdin
 *
 * Return: allocated line string, or NULL on EOF
 */
static char *prompt_and_read(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		return (NULL);
	}
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	return (line);
}

/**
 * process_line - parse and execute one input line
 * @line: input line to process
 * @prog_name: shell program name for error messages
 * @env: environment variables array
 * @status: exit status of the last command
 *
 * Return: updated exit status
 */
static int process_line(char *line, char *prog_name, char **env, int status)
{
	char **args;
	int builtin_ret;

	if (line[0] == '\0')
		return (status);
	args = parse_line(line);
	if (!args || !args[0])
	{
		free(args);
		return (status);
	}
	builtin_ret = handle_builtin(args, status, env);
	if (builtin_ret == 2)
	{
		free(args);
		free(line);
		exit(status);
	}
	if (builtin_ret == 1)
	{
		free(args);
		return (status);
	}
	status = execute(args, prog_name, env);
	free(args);
	return (status);
}

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
	char *line;
	int status = 0;

	(void)ac;
	while (1)
	{
		line = prompt_and_read();
		if (!line)
			break;
		status = process_line(line, av[0], env, status);
		free(line);
	}
	return (status);
}
