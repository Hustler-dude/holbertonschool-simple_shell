#include "shell.h"

/**
 * get_path_env - extract the PATH value from environment
 * @env: null-terminated array of environment strings
 *
 * Return: pointer to PATH value, or NULL if not found
 */
static char *get_path_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
	}
	return (NULL);
}

/**
 * find_in_path - find the full executable path of a command
 * @cmd: command to search for
 * @env: environment variables array
 *
 * Return: cmd itself if it contains '/' and is executable,
 *         malloc'd full path if found in PATH, NULL otherwise
 */
char *find_in_path(char *cmd, char **env)
{
	char *path_env, *path_copy, *dir, *full_path;
	size_t len;

	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	path_env = get_path_env(env);
	if (!path_env)
		return (NULL);
	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
