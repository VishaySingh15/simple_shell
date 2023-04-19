#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

/*
 * Executes system calls
 */

void execute(cmd *cmd_struct)
{
	pid_t child_pid;
	char *file_path = cmd_struct->argv[0];

	if (check_file(file_path))
	{
		if ((child_pid = fork()) < 0)
		{
			perror("Fork Error");
			exit(1);
		}
		//In child process therefore, execute command
		else if (child_pid == 0)
		{
			// Check if command is recognized by system
			if (execve(cmd_struct->argv[0], cmd_struct->argv, NULL) < 0)
			{
				perror("Unrecognized command");
				exit(1);
			}
		}
		// I am in parent process
		else
		{
			// Wait for child to finish
			wait(&child_pid);
		}
	}
	else if (execve(cmd_struct->argv[0], cmd_struct->argv, NULL) < 0)
	{
		perror("Unrecognized command");
	}	
}
