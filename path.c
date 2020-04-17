#include "holberton.h"
/**
 * fpath - function that search commands into the PATH.
 * @args: pointer that contains all the arguments of the program.
 * Return: 0 On success or -1 on error.
 */
int fpath(char **args)
{
	int i = 0, j = 0;
	char *tmp = NULL, *token[32], *cwd = NULL, *argumentitos = NULL;
	struct stat st;

	cwd = getcwd(NULL, 0);
	for (i = 0; environ[i] != NULL; i++)
		if (_strncmp(environ[i], "PATH=") == 0)
			break;
	tmp = _strdup(environ[i]);
	_split(tmp, "=:", token);
	for (j = 0; token[j] != NULL; j++)
	{
		if (args[0][0] == '/')
			break;
		if (_strncmp(args[0], "./") == 0)
			break;
		chdir(token[j]);
		if (stat(args[0], &st) == 0)
		{
			argumentitos = _strconcat(token[j], args[0]);
			if (argumentitos == NULL)
			{
				free(cwd);
				return (-1);
			}
			args[0] = argumentitos;
			free(argumentitos);
			break;
		}
	}
	chdir(cwd), free(cwd), free(tmp);
	if (token[j] == NULL)
	{
		return (-1);
	}
	return (0);
}
