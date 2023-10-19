#include "main.h"

/**
 * *read_input - reading user's input to the shell
 * Return: pointer to the read characters
*/

char *read_input(void)
{
	size_t line_size = 0;
	char *line = NULL;
	ssize_t n_read;
	int check = 0;

	check = isatty(STDIN_FILENO);

	n_read = getline(&line, &line_size, stdin);
	if (n_read == -1)
	{
		if (check)
			printline();
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}

/**
 * handle_input - handles comments
 * Return: pointer to the buffer_chars read before the comment
*/

char *handle_input(void)
{
	int x = 0;
	char *line;

	line = read_input();
	if (line == NULL)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	if (line[x] == '\n')
		line[x] = '\0';

	while (line[x] != '\0')
	{
		if (line[x] == '#')
		{
			line[x] = '\0';
			break;
		}
		x++;
	}
	return (line);
}

/**
 * _getline - geting input from user
 * @lineptr: pointer to input
 * @n: size
 * @stream: stream I/O
 * Return: read characters/buffer
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}

/**
 * free_all - free memory
 * @buffer_char: buffer char read
 * @line: pointer to user's input
 * Return: none
*/
void free_all(char *buffer_char, char *line)
{
	free(buffer_char);
	free(line);
}
