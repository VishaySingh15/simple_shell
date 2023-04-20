#include "shell.h"
/*
 * Example of a builtin function
 */
/*
void my_cd(cmd *cmd_struct)
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
*/
void my_exit(cmd *cmd_struct)
{
	int count = 0;

	while (cmd_struct->argv[count])
	{
		free (cmd_struct->argv[count]);
		count++;
	}
	free(cmd_struct);
	exit(0);
}

void my_env(cmd *cmd_struct)
{
	int count = 0;
	size_t nbytes_environ, count_letters;
	char new_line = '\n';

	while (cmd_struct->env[count])
	{
		count_letters = 0;
		while (cmd_struct->env[count][count_letters])
		{
			count_letters++;
		}
		nbytes_environ = count_letters;
		write(STDIN_FILENO, cmd_struct->env[count], nbytes_environ);
		//printf("%s\n", environ[count]);
		count++;
		write(STDIN_FILENO, &new_line, 1);
	}
}
