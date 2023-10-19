#include "main.h"

/**
 * tokenize_line - parsing the input into pieces
 * @buffer_char: read input from the user
 * @arguments_array: vector to arguments
 * Return: nothing
*/

void tokenize_line(char *buffer_char, char *arguments_array[])
{
	char *tokens;
	int x = 0;

	tokens = _strtok(buffer_char, " \t\r\n\a\"");
	while (tokens != NULL)
	{
		arguments_array[x] = tokens;
		tokens = _strtok(NULL, " \t\r\n\a\"");
		x++;
	}
	arguments_array[x] = NULL;
}

/**
 * full_path - create full path/directory
 * @full_path: pointer to the stored the full directories in the PATH
 * @size: size after _strcat & _strncat
 * @directories_array: directories
 * @arguments_array: arguments after tokenization
 * Return: nothing
*/

void full_path(char *full_path, size_t size,
char *directories_array, char *arguments_array)
{
	full_path[0] = '\0';

	_strcat(full_path, directories_array);
	_strcat(full_path, "/");
	_strncat(full_path, arguments_array, (size - _strlen(full_path) - 1));
}
