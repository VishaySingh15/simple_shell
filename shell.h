#ifndef _SHELL_
#define _SHELL_
#define MAXARGS 128

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * struct cmd - holds all arguments and is most important.
 * cmd: command.
 * Description: structure for commands.
 */
typedef struct cmd
{
	int argc;
	char *argv[MAXARGS];
} cmd;

/**
 * struct builtins - defines what our builtin functions
 * @instructions: instructions
 * @func: function.
 * Descriiption: structure or builtin commands.
 */
typedef struct builtins
{
	char *instruction;
	void (*func)(cmd*, char**);
} builtins_table;

void parse(char *command);
void execute(struct cmd *cmd_struct);
void (*is_builtin(char *command))(cmd *cmd_struct, char **environ);
void my_cd(cmd *cmd_struct, char **environ);
void eval(cmd *cmd_struct);

/* String functions that we can write to assist us */
int _strcmp(char *s1, char *s2);
char *get_env_var(char **environ, char *var);
char *check_var(char *env_var, char *var);
void handle_path(cmd *cmd_struct);
char *_strcat(char *dest, char *src);

/* Helpers */
int check_file(char *file);
char **environ;
const char *prompt = "myshell> ";
size_t nbytes = sizeof(prompt), line_size = 1024;

#endif
