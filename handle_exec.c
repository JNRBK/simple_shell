#include "main.h"

/**
 * execute - exec like function
 * @filename: pointer to char
 * @argv: argument vector
 * @env: environment
 * Return: This function does not return on success. It only returns on error.
 */
int execute(char *filename, char *const argv[], char **env)
{
	char *path;
	char *tokens;
	char c_path[4096];
	struct stat st;

	if (strchr(filename, '/') != NULL)
	{
		execve(filename, argv, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}

	path = getenv("PATH");
	if (path == NULL)
	{
		exit(EXIT_FAILURE);
	}

	tokens = _strtok(path, ":");
	while (tokens != NULL)
	{
		full_path(c_path, sizeof(c_path), tokens, filename);
		if (stat(c_path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			execve(c_path, argv, env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		tokens = _strtok(NULL, ":");
	}
	printstr(filename);
	printstr(": ");
	printstr("not found");
	printline();
	exit(EXIT_FAILURE);
}
