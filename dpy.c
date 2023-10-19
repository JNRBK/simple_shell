#include "shell.h"
/**
 * exit_st - function to check exit status
 * @wstatus: sig/exit status
 * Return: status
*/

int exit_st(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus));
	else if (WIFSTOPPED(wstatus))
		return (WSTOPSIG(wstatus));
	else
		return (ERROR);
}

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
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		n_read = getline(&buffer_char, &buffer, stdin);
		if (n_read == -1)
		{
			if (check)
				printstr("\n");
			free(buffer_char);
			exit(EXIT_SUCCESS);
		}
		if (buffer_char[x] == '\n')
			buffer_char[x] = '\0';

		while (buffer_char[x] != '\0')
		{
			if (buffer_char[x] == '#')
			{
				buffer_char[x] = '\0';
				break;
			}
			x++;
		}
		tokens = strtok(buffer_char, " \t\r\n\"");
		while (tokens != NULL)
		{
			av[x] = tokens;
			tokens = strtok(NULL, " \t\r\n\"");
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
			wstatus = exit_st(wstatus);
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
