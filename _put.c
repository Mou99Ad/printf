#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, return the character written.
 * On error, return -1 and set errno.
*/

int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to write
 *
 * Return: The number of characters written.
*/

int _puts(char *str)
{
	int i = 0;

	while (str && str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
