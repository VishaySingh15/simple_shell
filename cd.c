#include "shell.h"
/**
 * my_cd - handles cd command.
 * @cmd_struct: command structure.
 * @environ: environment variable.
 * Return: void.
 */
void my_cd(cmd *cmd_struct, char **environ)
{
	char *env_var;

	if (_strcmp(cmd_struct->argv[1], "-") == 0)
	{
		env_var = get_env_var(environ, "HOME");
		if (env_var)
		{
			if (chdir(env_var) != 0)
			{
				printf("Error changing dir");
			}
		}
		else
		{
			printf("variable not found");
		}
	}
}
