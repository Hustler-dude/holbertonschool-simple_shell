#include "shell.h"

/**
 * parse_line - split an input line into an array of tokens
 * @line: input string modified in place by strtok
 *
 * Return: null-terminated array of token pointers, NULL on malloc failure
 */
char **parse_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);
	token = strtok(line, " \t");
	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	tokens[i] = NULL;
	return (tokens);
}
