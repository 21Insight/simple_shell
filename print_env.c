#include "holberton.h"
/**
 * print_env - function that prints the enviroment variable.
 * Return: always 0.
 */
int print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
