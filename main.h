#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define _GNU_SOURCE
#define MAX_ARGS 24
#define MAX_PID 16
#define BUFFER_S 1024

#define NOT_FOUND 127
#define NOT_EXEC 126
#define ERROR -1


void printprompt(void);
void printline(void);
int printstr(char *str);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


char *read_input(void);
char *handle_hash(char *line);

char *handle_input(void);


int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, size_t n);
char *_strtok(char *str, char *delim);
char *_strdup(char *str);



void execute_external_command(__attribute__((unused)) char *command,
char *arguments_list[], char *env[]);

int execute(char *filename, char *const argv[], char **env);
void tokenize_line(char *buffer_char, char *arguments_array[]);
void full_path(char *full_path, size_t size,
char *directories_array, char *arguments_array);


void handle_arguments(int argc, char *line, char **env);



void built_env(char *arguments_list[], int argc,
__attribute__((unused)) char *env[]);
void built_exit(char *arguments_list[], int argc);

int exit_st(int wstatus);


void shell_loop(int argc, char **env);
void free_all(char *buffer_char, char *line);

void err_msg1(void);
void err_msg2(void);

#endif
