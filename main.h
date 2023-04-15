#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
char *strtok(char *str, const char *delim);
extern char *strcpy (char *__restrict __dest, const char *__restrict __src);
extern char *strtok (char *__restrict __s, const char *__restrict __delim);

#endif
