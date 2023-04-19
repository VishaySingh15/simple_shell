#include "shell.h"
#include <stdio.h>

/**
 * eval - Determines whether the command is builtin,
 * system or invalid and takes action.
 * Return: void.
 */

extern char **environ;

void eval(cmd *cmd_struct)
{
	void (*func)(cmd *cmd_struct, char **environ)
		= is_builtin(cmd_struct->argv[0]);

	if (func)
	{
		func(cmd_struct, environ);
	}
	else
	{
		handle_path(cmd_struct);
		execute(cmd_struct);
	}
}
