#include "main.h"

/**
 * built_exit - function to implement exit command
 * @arguments_list: pointer to arguments_list's array
 * @argc: arguments count
 * Return: nothing
*/
void built_exit(char *arguments_list[], int argc)
{
	if ((_strcmp(arguments_list[0], "exit") == 0) && (argc == 1))
	{
		if (arguments_list == NULL)
		{
			return;
		}
		exit(EXIT_SUCCESS);
	}
}

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
