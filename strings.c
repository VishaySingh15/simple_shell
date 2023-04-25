#include "shell.h"

/**
 * _strcmp - Compares 2 strings
 * @s1: String 1 pointer
 * @s2: String 2 pointer
 * Return: -15 - for s1 > s2, 15 for s2 > s1, 0 for s1 = s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if (!s1[i] && !s2[i])
		{
			break;
		}
		op = s1[i] - s2[i];
		i++;
	}

	return (op);
}

/**
 * get_env_var - gets environment variable.
 * @environ: environment parameter.
 * @var: variable parameter.
 * Return: environment variable.
 */

char *get_env_var(char **environ, char *var)
{
	int count = 0;
	char *env_var, *ret_var;

	while ((env_var = environ[count]) != NULL)
	{
		ret_var = check_var(env_var, var);
		if (ret_var)
			return (ret_var);
		count++;
	}
	return (NULL);
}

/**
 * check_var - checks environment variable.
 * @env_var: environment variable parameter.
 * @var: variable parameter.
 * Return: environmen variable
 */

char *check_var(char *env_var, char *var)
{
	int letter = 0;

	while (var[letter] != 0)
	{
		if (env_var[letter] != var[letter])
		{
			return (NULL);
		}
		letter++;
	}
	return (&env_var[letter + 1]);
}

/**
 * handle_path - handles PATH.
 * @cmd_struct: command structure.
 * Return: void.
 */

void handle_path(cmd *cmd_struct)
{
	char *new_path, checkpath[20] = "/bin/";
	int count = 0;

	while (count < 4)
	{
		if (cmd_struct->argv[0][count] != checkpath[count])
		{
			new_path = _strcat(checkpath, cmd_struct->argv[0]);
			free(cmd_struct->argv[0]);
			cmd_struct->argv[0] = new_path;
		}
		count++;
	}
}

/**
 * _strcat - Copies string from source
 * pointer and appends to destination pointer
 * @dest: String pointer for destination
 * @src: String pointer for source
 * Return: dest - string pointer to destination
 */

char *_strcat(char *dest, char *src)
{
	int len_dest = 0, len_src = 0;

	while (dest[len_dest] != 0)
	{
		len_dest++;
	}
	while (src[len_src] != 0)
	{
		dest[len_dest] = src[len_src];
		len_dest++;
		len_src++;
	}
	dest[len_dest] = 0;
	return (dest);
}
