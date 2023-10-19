#include "main.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: vector to arguments
 * @env: vector to environ
 * Return: 0; success
*/

int main(int argc, __attribute__((unused)) char *argv[], char *env[])
{
	int check;
	char *buffer_char = NULL;
	char *line = NULL;
	char *arguments_list[MAX_ARGS];

	check = isatty(STDIN_FILENO);
	while (1)
	{
		if (check)
			printprompt();

		free(buffer_char);
		line = handle_input();
		tokenize_line(line, arguments_list);
		built_exit(arguments_list, argc);
		built_env(arguments_list, argc, env);
		execute_external_command(arguments_list[0], arguments_list, env);
	}
	free(line);
	return (0);
}
