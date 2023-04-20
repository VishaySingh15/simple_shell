#include "shell.h"
#include <sys/stat.h>
#include <sys/types.h>

/**
 * check_file - checks the file.
 * @file: file to be checked.
 * Return: 1 if file found, 0 otherwise
 */

int check_file(char *file)
{
	struct stat st;

	if (stat(file, &st) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
