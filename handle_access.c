#include "main.h"
/**
 * execute_external_command - check if command is accessible or not
 * @command: command to be checked
 * @arguments_list: pointer to arguments_list's array
 * @env: environment
 * Return: value to be checked
*/
void execute_external_command(__attribute__((unused)) char *command,
char *arguments_list[], char *env[])
{
	int wstatus = 0;
	pid_t pid;

	if (access(arguments_list[0], F_OK) != 0)
	{
		if (access(arguments_list[0], X_OK) != 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execute(arguments_list[0], arguments_list, env) == -1)
				{
					perror("Execution failed");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				if (wait(&wstatus) == -1)
					perror("wait");
				else
				wstatus = exit_st(wstatus);
			}
		}
		else
			err_msg1();
	}
	else
		err_msg2();
}

/**
 * err_msg1 - error messages 4 Access
 * Return: nothing
*/
void err_msg1(void)
{
	printstr("Access denied: No execute permission.");
	printline();
}

/**
 * err_msg2 - error messages 4 Not found
 * Return: nothing
*/
void err_msg2(void)
{
	printstr("File not found.");
	printline();
}
