#include "shell.h"

/**
 * eval - Determines whether the command is builtin,
 * system or invalid and takes action.
 * @cmd_struct: command structure.
 * Return: void.
 */

void eval(cmd *cmd_struct)
{
	char *new_p;

	void (*func)(cmd *cmd_struct) = is_builtin(cmd_struct->argv[0]);

	if (func)
	{
		func(cmd_struct);
	}
	else
	{
		new_p = handle_path(cmd_struct);
		printf("Path from eval %s", new_p);
		execute(cmd_struct, new_p);
	}
}
