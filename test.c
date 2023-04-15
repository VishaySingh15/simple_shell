#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Entry point.
 * Return: void.
 */

int main(void)
{
	char *command_full = NULL;
	char *command_copied = NULL;
	size_t n = 0;
	ssize_t read_chars; /* number of characters the user types */
	char *token;
	const char *delim = " \n";
	char **argv;
	int i = 0;
	int token_number = 0;

	/* print a prompt for the user to type something */
	printf("$ ");

	/* get the string that the user types in and pass it to full_command */
	read_chars = getline(&command_full, &n, stdin);

	/* let's allocate space to store the characters read by getline */
	command_copied = malloc(sizeof(char) * read_chars);

	if (command_copied == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}

	/* make a copy of the command that was typed */
	strcpy(command_copied, command_full);

	/* check if the getline function failed or reached EOF or user use CTRL + D */
	if (read_chars == -1)
	{
		printf("Exiting simple_shell....\n");
		return (-1);
	}
	else
	{
		/* split the string (full_command) into an array of words */
		token = strtok(command_full, delim);

		/* allocate space to store the variable arguments but before then determine how many tokens are there*/
		while (token != NULL)
		{
			token_number++;
			token = strtok(NULL, delim);
		}
		token_number++;
		/* use malloc to allocate enough space for the pointer to the argument variables */
		argv = malloc(sizeof(char *) * token_number);
		token = strtok(command_copied, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/* execute the commands with execve */
		free(argv);
		free(command_full);
		free(command_copied);
	}
	return (0);
}
