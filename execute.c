#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute - Executes system calls
 * @cmd_struct: command structure
 * Return: no return
 */

void execute(cmd *cmd_struct, char *new_path)
{
	pid_t child_pid;
	char *err = ": 1: ";
	size_t err_size = sizeof(err), home_size;
	/*char *file_path = cmd_struct->argv[0];*/

	if (check_file(new_path))
	{
		while ((child_pid = fork()) < 0)
		{
			home_size = sizeof(cmd_struct->home);
			write(STDIN_FILENO, cmd_struct->home, home_size);
			write(STDIN_FILENO, err, err_size);
			perror(cmd_struct->argv[0]);
			exit(1);
		}
		/* In child process therefore, execute command */
		if (child_pid == 0)
		{
			/* Check if command is recognized by system */
			if (execve(new_path, cmd_struct->argv, cmd_struct->env) < 0)
			{
				write(
				perror("Unrecognized");
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
	else if (execve(new_path, cmd_struct->argv, NULL) < 0)
	{
		home_size = sizeof(cmd_struct->home);
		write(STDIN_FILENO, cmd_struct->home, home_size);
		write(STDIN_FILENO, err, err_size);
		perror(cmd_struct->argv[0]);
	}
}
