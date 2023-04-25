#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Entry point
 * Return: void.
 */

int main(int argc, char **argv)
{
	int nread;
	char *command =  malloc(3);
	const char *prompt = "myshell> ";
	size_t nbytes = sizeof(prompt), line_size = 1024;

	if (argc > 1)
	{
		printf("%s", argv[0]);
	}
	else
	{
		while (1)
		{
			write(STDIN_FILENO, prompt, nbytes);
			nread = getline(&command, &line_size, stdin);
			if (nread == -1)
			{
				return (0);
			}
			else if (nread > 1)
			{
				command[nread - 1] = '\0';
				if (command)
					parse(command, environ);
			}
		}
	}
		
}
