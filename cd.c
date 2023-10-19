#include "shell.h"

void cd_command(char *directory)
{
	char *path = NULL;

	if (directory == NULL)
	{
		path = getenv("HOME");
	}
	else if (_strcmp(directory, "-") == 0)
	{
		path = getenv("OLDPWD");
	}
	else
	{
		path = (char *)directory;
	}
	if (path == NULL)
	{
		fprintf(stderr, "cd: HOME not set\n");
	}
	else
	{
		char current_dir[256];
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("cd");
		return;
	}
		setenv("OLDPWD", current_dir, 1);
	if (chdir(path) != 0)
	{
		perror("cd");
	}
	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
	{
		setenv("PWD", current_dir, 1);
	}
	else
	{
		perror("cd");
	}
	}
}
