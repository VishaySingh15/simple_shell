#include "shell.h"
#include <stdio.h>
/**
 * is_builtin - checks if command is a built in command.
 * @command: command to be checked.
 * Return: 0.
 */
void (*is_builtin(char *command))(cmd * cmd_struct, char **environ)
{
	int count;

	builtins_table my_builtins[] = {
		{"cd", my_cd},
		{NULL, NULL}
	};
	for (count = 0; my_builtins[count].instruction; count++)
	{
		if (_strcmp(my_builtins[count].instruction, command) == 0)
		{
			return (my_builtins[count].func);
		}
	}
	return (NULL);
}
