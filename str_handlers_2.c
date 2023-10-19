#include "main.h"

/**
 * _strtok - split strings using delimeters
 * @str: string passed on
 * @delim: delimeters
 * Return: splitted tokens
*/
char *_strtok(char *str, char *delim)
{
	return (strtok(str, delim));
}

/**
 * _strdup - returns a pointer to a copy of the string given as a parameter.
 * @str: the to be copied string.
 * Return: pointer to a newly allocated space in memory.
*/

char *_strdup(char *str)
{
	unsigned int i;
	char *s;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	;

	s = malloc(sizeof(*str) * (i + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		s[i] = str[i];

	s[i] = '\0';
	return (s);
	free(s);
	return (0);
}

/**
 * _strncmp - Compare two string
 * @str1: 1st string
 * @str2: 2nd string
 * @n: number of bytes
 * Return: 0
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	size_t x;

	for (x = 0; str1[x] && str2[x] && x < n; x++)
	{
		if (str1[x] > str2[x])
		{
			return (str1[x] - str2[x]);
		}
		else if (str1[x] < str2[x])
		{
			return (str1[x] - str2[x]);
		}
	}
	if (x == n)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}
