#include "shell.h"

/**
 * printstr - printf like function
 * @str: pointer to char to be printed
 * Return: function
*/
int printstr(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}
/**
 * execute - exec like function
 * @filename: pointer to char
 * @argv: argument victor
 * @environ: environment extern
 * Return: 0
*/
int execute(char *filename, char *const argv[], char **const environ);
int execute(char *filename, char *const argv[], char **const environ)
{
	char *path;
	char *token;
	char full_path[MAX_PATH_LENGTH];
	struct stat st;
	char errmsg[] = "Command not found: ";

	if (_strchr(filename, '/') != NULL)
	{
		execve(filename, argv, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	path = getenv("PATH");
	if (path == NULL)
	{
		return (0);
	}
	token = strtok(path, ":");
while (token != NULL)
{
	int path_length = _strlen(token);
	int filename_length = _strlen(filename);

	if (path_length + filename_length + 1 <= MAX_PATH_LENGTH)
	{
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, filename);
		if (stat(full_path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			execve(full_path, argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(STDERR_FILENO, "Path exceeds maximum length\n", 28);
	}
	token = strtok(NULL, ":");
}
	write(STDERR_FILENO, errmsg, _strlen(errmsg));
	write(STDERR_FILENO, filename, _strlen(filename));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
	return (0);
}
