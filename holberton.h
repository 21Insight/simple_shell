#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdarg.h>
#include <time.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITERS " \t\n\r"

extern char **environ;
void *_calloc(unsigned int nmemb, unsigned int size);
void err(char **argv, char **args, int times);
void itoa_err(int times);
int _atoi(char *s);
char *_strdup(char *str);
int _strlen(char *s);
char *_strncat(char *dest, char *src, int n);
int _strncmp(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char **_split(char *buffer, char *delimiters);
int execute_function(char **argv, char **args, int times, int *exit_val);
void free_doubleptr(char **args);
int print_env(void);
void check_exit(char **args, char *buffer, int exit_value);
int fpath(char **args);
char *_strcat(char *dest, char *src);
char *str_concat(char *s1, char *s2);
int count_args(char *args);
char *_strconcat(char *s1, char *s2);
void ctrlc_handler(int signal);

#endif /* HOLBERTON_H */
