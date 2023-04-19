#include "shell.h"
#include <sys/stat.h>
#include <sys/types.h>

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
