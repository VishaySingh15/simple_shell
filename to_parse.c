#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * strtok - reads the user input and breaks the command
 * into individual strings to execute them as commands.
 * @str: the string to be tokenized.
 * @delim: chars we expect to separate the string into tokens.
 * Return: 0.
 */

char copy_lineptr = NULL;
const char delim = " \n";
