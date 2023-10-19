#include "shell.h"
/**
 * main - main function for the shell prompt
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
*/
int main(int argc, __attribute__((unused)) char *argv[]);
int main(int argc, __attribute__((unused)) char *argv[])
{
	unsigned int i = 0, x = 0;
	ssize_t check;
	pid_t pid;
	size_t buffer = 1024;
	char *buffer_char = NULL, *tokens;
	int wstatus, n_read;
	char *av[24] = {NULL};

	check = isatty(STDIN_FILENO);
	while (1)
	{
		if (check)
			write(1, "$ ", _strlen("$ "));
		n_read = getline(&buffer_char, &buffer, stdin);
		if (n_read == -1)
		{
			printstr("\n");
			break;
		}

		tokens = strtok(buffer_char, " \n\t");
		while (tokens != NULL)
		{
			av[x] = tokens;
			tokens = strtok(NULL, " \n\t");
			x++;
		}
		av[x] = NULL;

		if ((_strcmp(buffer_char, "exit") == 0) && (argc == 1))
		{
			break;
		}

		if ((_strcmp(buffer_char, "env") == 0) && (argc == 1))
		{
			for (; environ[i] != NULL; i++)
			{
				printstr(environ[i]);
				printstr("\n");
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execute(av[0], av, environ) == -1)
			{
				perror("Execution failed");
				free(buffer_char);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&wstatus) == -1)
				perror("wait");
		}
		free(buffer_char);
		buffer_char = NULL;
	   x = 0;
		if (check == 0)
			break;
	}
	free(buffer_char);
	return (0);
}
