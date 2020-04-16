#include "holberton.h"
/**
 * err - function that print the error message.
 * @argv: arguments passed to the program.
 * @args: pointer that contains all the arguments of the program.
 * @times: number of times that the prompt has executed.
 * Return: Nothing, it is a void function :D
 */
void err(char **argv, char **args, int times)
{
	char *sep = ": ";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, sep, _strlen(sep));
	/* -------------------------------------*/
	itoa_err(times);
	/* -------------------------------------*/
	write(STDERR_FILENO, sep, _strlen(sep));
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, sep, _strlen(sep));
	write(STDERR_FILENO, "not found\n", 10);
}
/**
 * itoa_err - function that converts int into string and print each one of int.
 * @times: number of times that the prompt has executed.
 * Return: Nothing, it is a void function.
 */
void itoa_err(int times)
{
	int x = 1;
	unsigned int n = times;
	char num;

	while ((n / x) > 9)
		x *= 10;

	while (x >= 1)
	{
		num = ((n / x) % 10) + '0';
		write(STDERR_FILENO, &num, 1);
		x /= 10;
	}
}
