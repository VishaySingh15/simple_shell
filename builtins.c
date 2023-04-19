#include "shell.h"
#include <stdio.h>
/*
 * Framework for how builtins can be used
 */
void (*is_builtin(char *command))(cmd *cmd_struct, char **environ)
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
