# Simple Shell

A simple UNIX command line interpreter written in C, replicating the behavior of `/bin/sh`.

## Description

`hsh` is a simple shell that reads commands from standard input (interactive or non-interactive),
searches for executables in the PATH, and executes them using `fork` and `execve`.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive mode

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.h
($) ls -l
total 32
-rwxr-xr-x 1 user user 16000 Apr 23 12:00 hsh
($) exit
$
```

### Non-interactive mode

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.h
$ echo "ls -la" | ./hsh
total 32
-rwxr-xr-x 1 user user 16000 Apr 23 12:00 hsh
```

## Built-in Commands

| Command | Description |
|---------|-------------|
| `exit`  | Exit the shell |
| `env`   | Print the current environment |

## Features

- Displays a prompt and waits for user input
- Executes commands found in the PATH
- Handles commands with arguments
- Handles EOF (Ctrl+D)
- Handles empty lines and extra spaces
- Prints error messages matching `/bin/sh` format

## Error Handling

```bash
$ ./hsh
($) qwerty
./hsh: 1: qwerty: not found
($)
```

## Files

| File | Description |
|------|-------------|
| `main.c` | Main loop — prompt, read, dispatch |
| `executor.c` | fork + execve logic |
| `parser.c` | Tokenize input line |
| `path.c` | Search command in PATH |
| `builtins.c` | Built-in commands (exit, env) |
| `errors.c` | Error message formatting |
| `memory.c` | Memory cleanup helpers |
| `shell.h` | Header — all prototypes and includes |

## Authors

Desmond Ondai
