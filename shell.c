#include "holberton.h"
/**
 * main - program that interprets commands.
 * @argc: number of args.
 * @argv: arguments passed to the program.
 * Return: 0 on success or other value.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *buffer = NULL, **args = NULL;
	size_t length_buff = 0;
	int times = 0;
	int exit_value = 0, *exit_num = &exit_value;

	signal(SIGINT, ctrlc_handler);
	for (times = 1; 1; times++)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		if (getline(&buffer, &length_buff, stdin) == EOF)
		{
			free(buffer);
			if (isatty(STDIN_FILENO))
				write(STDERR_FILENO, "\n", 1);
			return (exit_value);
		}
		if (_strcmp(buffer, "env") == 0)
			print_env();
		if (*buffer != '\n')
		{
			args = _split(buffer, DELIMITERS);
			if ((_strcmp(args[0], "exit") && _strlen("exit") == 4) == 0)
				check_exit(args, buffer, exit_value);
			fpath(args);
			execute_function(argv, args, times, exit_num);
			free_doubleptr(args);
		}
	}
	return (exit_value);
}
