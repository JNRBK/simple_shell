#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 4096
#define _GNU_SOURCE
#define ERROR -1

extern char **environ;

void cd_command(char *directory);
int printstr(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int execute(char *filename, char *const argv[], char **const environ);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);
int exit_st(int wstatus);

#endif
