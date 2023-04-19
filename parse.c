#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/*
 * Tokenizes the string (splits words based on space character) and sends to eval
 */

void parse(char *command)
{
	cmd *cmd_struct = malloc(sizeof(cmd));
	char *token;
	const char *delim = " ";

	cmd_struct->argc = 0;
	/* Tokenize command string */
	token = strtok(command, delim);
	/* Add token to argv list for execve */
	(cmd_struct->argv)[cmd_struct->argc] =  token;
	while (token != NULL)
	{
		cmd_struct->argc++;
		token = strtok(NULL, delim);
		(cmd_struct->argv)[cmd_struct->argc] =  token;
	}
	/* Ensure Command is tokenized
	while (cmd_struct->argv[count] != NULL)
	{
		printf("%s\n", cmd_struct->argv[count]);
		count++;
	}
	*/
	eval(cmd_struct);
}
