#include "shell.h"
/*
 * Example of a builtin function
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
