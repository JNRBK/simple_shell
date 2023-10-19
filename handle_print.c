#include "main.h"

/**
 * printprompt - print the prompt to the user
 * Return: welcoming message
*/
void printprompt(void)
{
	write(STDOUT_FILENO, "$ ", strlen("$ "));
}

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
 * printline - print newline
 * Return: nothing
*/
void printline(void)
{
	write(STDOUT_FILENO, "\n", strlen("\n"));
}
