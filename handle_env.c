#include "main.h"

/**
 * built_env - function to print env
 * @arguments_list: pointer to arguments_list's array
 * @argc: arguments count
 * @env: vector to environ
 * Return: nothing
*/

void built_env(char *arguments_list[], int argc,
__attribute__((unused)) char *env[])
{
	int i = 0;

	if ((strcmp(arguments_list[0], "env") == 0) && (argc == 1))
	{
		for (; env[i] != NULL; i++)
		{
			printstr(env[i]);
			printline();
		}
	}
}
