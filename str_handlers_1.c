#include "main.h"

/**
 * _strlen - length of a string
 * @str: pointer to string chars
 * Return: length
*/
int _strlen(char *str)
{
	int x = 0;

	for (; *str != '\0'; ++str)
	{
		++x;
	}
	return (x);
}
/**
 * _strcmp - function to compare between strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}
/**
 * _strcpy - copies string
 * @dest: destination to copy to
 * @src: source to be copied from
 * Return: void
*/
char *_strcpy(char *dest, char *src)
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
	char *d;
	char *s;

	d = dest;
	s = src;
	while (*d != '\0')
		d++;

	while (*s != '\0')
	{
		*d++ = *s++;
	}
		*d = '\0';
	return (d);
}
/**
 * _strncat - concatenates two strings with n of bytes from src
 * @dest: destination
 * @src: source
 * @n: n of bytes from src
 * Return: dest
*/
char *_strncat(char *dest, char *src, size_t n)
{
	size_t len = _strlen(dest);
	size_t x;

	for (x = 0; x < n && src[x] != '\0'; x++)
	dest[len + x] = src[x];

	dest[len + x] = '\0';
	return (dest);
}
