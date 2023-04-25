#include "shell.h"

/**
 * execute - Executes system calls
 * @cmd_struct: command structure
 * @newpath: path of file
 * Return: no return
 */

void execute(cmd *cmd_struct, char *newpath)
{
	pid_t child_pid;
	char err[] = ": 1: ";
	size_t err_size = sizeof(err), home_size;

	printf("in execution");
	home_size = get_len(cmd_struct->home);
	if (check_file(newpath))
	{
		while ((child_pid = fork()) < 0)
		{
			perror("fork error");
			exit(1);
		}
		/* In child process therefore, execute command */
		if (child_pid == 0)
		{
			/* Check if command is recognized by system */
			if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
			{
				write(STDIN_FILENO, cmd_struct->home, home_size);
				write(STDIN_FILENO, err, err_size);
				perror(cmd_struct->argv[0]);
				exit(1);
			}
		}
		/* I am in parent process */
		else
		{
			/* Wait for child to finish */
			wait(&child_pid);
		}
	}
	else if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
	{
		printf("%s", cmd_struct->home);
		write(STDOUT_FILENO, cmd_struct->home, home_size);
		write(STDOUT_FILENO, err, err_size);
		/*perror(cmd_struct->argv[0]);*/
	}
}
