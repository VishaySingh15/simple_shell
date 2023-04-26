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
	char err[] = ": 1: ", err2[] = ": ", not_found[] = "not found\n";
	size_t err_size = sizeof(err), home_size, err2_size = sizeof(err2), comm_size;
	size_t f_size = sizeof(not_found);

	home_size = get_len(cmd_struct->home);
	comm_size = get_len(cmd_struct->argv[0]);
	if (check_file(newpath))
	{
		while ((child_pid = fork()) < 0)
		{
			perror("fork error");
			exit(1);
		}
		if (child_pid == 0)
		{
			if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
			{
				write(STDIN_FILENO, cmd_struct->home, home_size);
				write(STDIN_FILENO, err, err_size);
				perror(cmd_struct->argv[0]);
				exit(1);
			}
		}
		else
		{
			wait(&child_pid);
		}
	}
	else if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
	{
		write(STDOUT_FILENO, cmd_struct->home, home_size);
		write(STDOUT_FILENO, err, err_size);
		write(STDOUT_FILENO, cmd_struct->argv[0], comm_size);
		write(STDOUT_FILENO, err2, err2_size);
		write(STDOUT_FILENO, not_found, f_size);
	}
}
