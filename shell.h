#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute(char **args, char *prog_name, char **env);
char **parse_line(char *line);
void print_error(char *prog_name, char *cmd);
char *find_in_path(char *cmd, char **env);
int handle_builtin(char **args, int last_status, char **env);

#endif /* SHELL_H */
