#include "holberton.h"
/**
 * _split - function tath splits a string by delimiters.
 * @buffer: string that contains all the arguments taked by getline.
 * @delimiters: delimiting characters.
 * Return: a double pointer with all the commands.
 */
void _split(char *buffer, char *delimiters, char **args)
{
	char *token = NULL;
	int i = 0;

	token = strtok(buffer, delimiters);

	while (token != NULL)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimiters);

		i++;
	}
	args[i] = NULL;
	free(token);
}
