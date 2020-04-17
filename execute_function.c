#include "holberton.h"
/**
 * execute_function - function that execute the command.
 * @argv: arguments from main.
 * @args: pointer that contains all the arguments of the program.
 * @times: number of times that the prompt has executed.
 * @exit_val: number to exit the program
 * Return: always 0
 */
int execute_function(char **argv, char **args, int times, int *exit_val)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			err(argv, args, times);
			exit(127);
		}
	}
	if (pid < 0)
	{
		free_doubleptr(args);
		exit(EXIT_FAILURE);
	}
	if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			*exit_val = WEXITSTATUS(status);
		}
	}
	return (0);
}
