#include "holberton.h"
/**
 * free_doubleptr - function that frees a double pointer.
 * @args: pointer that contains all the arguments of the program.
 * Return: Nothing, it is a void function :D
 */
void free_doubleptr(char **args)
{
	int height;

	for (height = 0; args[height] != NULL; height++)
	{}

	if (args != NULL && height != 0)
	{
		for (; height >= 0; height--)
		{
			free(args[height]);
		}
		free(args);
	}
}
