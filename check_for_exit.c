#include "holberton.h"
/**
 * check_exit - function that exits the program.
 * @args: pointer that contains all the arguments of the program.
 * @buffer: string that contains all the arguments taked by getline.
 * @exit_value: number to exit.
 * Return: Nothing, it is a void function :D
 */
void check_exit(char **args, char *buffer, int exit_value)
{
	if (_strncmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		exit_value = _atoi(args[1]);
		free(buffer);
		exit(exit_value);
	}
	else
	{
		free(buffer);
		exit(exit_value);
	}
}
