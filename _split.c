#include "holberton.h"
/**
 * _split - function tath splits a string by delimiters.
 * @buffer: string that contains all the arguments taked by getline.
 * @delimiters: delimiting characters.
 * Return: a double pointer with all the commands.
 */
char **_split(char *buffer, char *delimiters)
{
	char *token = NULL;
	char **args = malloc(sizeof(char *) * _strlen(buffer) + 1);
	int i = 0;

	if (args == NULL || buffer == NULL)
	{
		return (NULL);
	}

	token = strtok(buffer, delimiters);

	while (token != NULL)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimiters);

		i++;
	}
	args[i] = NULL;
	free(token);
	return (args);
}
