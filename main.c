#include "main.h"

/**
  * main - Entry Point.
  * @ac: argument count.
  * @argv: argument vector.
  * Return: 0.
  */

int main(int ac, char **argv)
{
	char *prompt = "(simple_shell) $ ";
	char *lineptr = NULL;
	char copy_lineptr = NULL;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t read_chars;
	char *token;
	int token_number = 0;
	int i;

	(void)ac;

/* this is a loop for the promt */
	while (1)
	{
		printf("%s", prompt);
		read_chars = getline(&lineptr, &n, stdin);
		if (read_chars == -1)
		{
			printf("Exiting simple shell...\n");
			return (-1);
		}

		/* allocates space for the copy of lineptr */
		copy_lineptr = malloc(sizeof(char) * read_chars);
		if (copy_lineptr == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		strcpy(char copy_lineptr, lineptr);

		/* this splits the string into and array of tokens */
		/* this calculates the total number of tokens */
		token = strtok(lintptr, delim);
		while (token != NULL)
		{
			token_number++;
			token = strtok(lineptr, delim);
		}
		token_number++;

		/* allocates space to hold the array of strings */
		argv = malloc(sizeof(char) * token_number);

		/* stores each token in the argv array */
		token = strtok(char copy_lineptr, delim);

		for (i = 0, token != NULL, i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		printf("%s\n", lineptr);
		free(lineptr);
	}
	return (0);
}
