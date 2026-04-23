# Simple Shell

A simple UNIX command line interpreter written in C, replicating the behavior of `/bin/sh`.

## Description

`hsh` is a simple shell that reads commands from standard input (interactive or non-interactive),
searches for executables in the PATH, and executes them using `fork` and `execve`.

## Requirements

- Ubuntu 20.04 LTS
- gcc with options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style compliant
- No memory leaks

## Allowed Functions

- All functions from `string.h`
- `access`, `chdir`, `close`, `closedir`
- `execve`, `exit`, `_exit`
- `fflush`, `fork`, `free`
- `getcwd`, `getline`, `getpid`
- `isatty`, `kill`
- `malloc`, `open`, `opendir`
- `perror`, `printf`, `fprintf`, `vfprintf`, `sprintf`, `putchar`
- `read`, `readdir`
- `signal`
- `stat` (`__xstat`), `lstat` (`__lxstat`), `fstat` (`__fxstat`)
- `strtok`
- `wait`, `waitpid`, `wait3`, `wait4`
- `write`

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

## Project Structure

```
holbertonschool-simple_shell/
├── shell.h         All function prototypes, macros, and includes
├── main.c          Entry point: main loop, prompt display, getline, dispatch
├── executor.c      Creates child process with fork(), runs command via execve()
├── parser.c        Splits raw input line into an array of tokens (args)
├── path.c          Searches for the command binary in each PATH directory
├── builtins.c      Handles built-in commands: exit and env
├── errors.c        Formats and prints error messages to stderr
├── memory.c        Frees dynamically allocated memory (args arrays, paths)
├── README.md       Project documentation
├── AUTHORS         List of contributors
└── man_1_simple_shell  Manual page for hsh
```

## Authors

Desmond Ondai
