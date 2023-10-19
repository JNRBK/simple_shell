#include "shell.h"
/**
 * _strncmp - Compare two string
 * @s1: 1st string
 * @s2: 2nd string
 * @n: number of bytes
 * Return: 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	for (x = 0; s1[x] && s2[x] && x < n; x++)
	{
		if (s1[x] > s2[x])
		{
			return (s1[x] - s2[x]);
		}
		else if (s1[x] < s2[x])
		{
			return (s1[x] - s2[x]);
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
/**
 * _strchr - search for specific character
 * @s: pointer to string
 * @c: character
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int chr;
	char *result;

	for (chr = 0; s[chr]; chr++)
	{
		if (s[chr] == c)
		{
			result = s + chr;
		}
		return (result);
	}

	return (NULL);
}
