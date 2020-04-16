#include "holberton.h"
/**
 * _strdup - function that returns a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string.
 * Return: Returns NULL if str = NULL or if insufficient memory was available
 */
char *_strdup(char *str)
{
	int i, count;
	char *dest;

	if (str == 0)
	{
		return (NULL);
	}

	count = 0;

	while (*(str + count) != '\0')
	{
		count++;
	}

	dest = malloc(sizeof(char) * (count + 2));

	if (dest == 0)
	{
		return (NULL);
	}

	for (i = 0; *(str + i) != '\0'; i++)
	{
		*(dest + i) = *(str + i);
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * _strlen - function that returns the length of a string..
 * @s: string
 * Return: the value of the variable count.
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/**
 * _strncat - function that concatenates two strings.
 * @dest: character.
 * @src: character.
 * @n: integer.
 * Return: the value of dest.
 */
char *_strncat(char *dest, char *src, int n)
{

	int i, j, c;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (c = 0; src[c] != '\0'; c++)
	{}
	if (n > c)
	{
		n = c;
	}
	for (j = 0; j < n;)
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}
/**
 * _strncmp - function that compares two strings.
 * @s1: string.
 * @s2: string.
 * Return: the difference between 2 strings.
 */
int _strncmp(char *s1, char *s2)
{
	int diff, i;

	diff = i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			break;
		i++;
	}
	return (diff);
}
/**
 * _strcmp - function that compares two strings.
 * @s1: character.
 * @s2: character.
 * Return: the value of j.
 */
int _strcmp(char *s1, char *s2)
{
	int i, j = 0;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
	}
	if (s1[i] != s2[i])
	{
		j = (s1[i] - s2[i]);
	}
	return (j);
}
