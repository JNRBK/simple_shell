#include "shell.h"
/**
 * _strlen - length of a string
 * @s: pointer to string chars
 * Return: length
*/
int _strlen(char *s)
{
	int count =  0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/**
 * _strcmp - function to compare between strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	i++;
	}
	return (0);
}
/**
 * _strcpy - copies string
 * @dest: destination to copy to
 * @src: source to be copied from
 * Return: void
*/
char *_strcpy(char *dest, const char *src)
{
	size_t x;

	for (x = 0; src[x] != '\0'; x++)
		dest[x] = src[x];
	dest[x] = '\0';
	return (dest);
}
/**
 * _strcat - concatenate two string
 * @dest: destination
 * @src: source
 * Return: dest
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strncat - concatenates two strings with n of bytes from src
 * @dest: destination
 * @src: source
 * @n: n of
 * Return: dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
