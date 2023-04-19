#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Entry point
 * Return: void.
 */

int main(void)
{
	int nread;
	char *command =  malloc(3);
	/*pid_t child_pid;*/

	while (1)
	{
		write(STDIN_FILENO, prompt, nbytes);
		nread = getline(&command, &line_size, stdin);
		if (nread == -1)
		{
			perror("Goodbye!");
			exit(0);
		}
		else if (nread > 1)
		{
			command[nread - 1] = '\0';
			if (command)
				parse(command);
		}
		/*
		 * Fork process to allow parsing, evaluation and
		 * execution to occur first. Then only prompt
		 * a user for a new command.
		 * if ((child_pid = fork()) < 0){
		 * perror("Fork Error");
		 * exit(1);}
		 * else if (child_pid == 0){
		 * parse(command);
		 * break; }
		 * else{
		 * wait (&child_pid);}
		 */
	}
}
