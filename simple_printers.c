#include "main.h"

/**
 * print_from_to - Print characters from start to stop (excluding except)
 * @start: Start character pointer
 * @stop: Stop character pointer
 * @except: Except character pointer
 *
 * Return: The number of characters printed
*/
int print_from_to(char *start, char *stop, char *except)
{
	int count = 0;

	while (*start && *start != *stop)
	{
		if (!except || !strchr(except, *start))
		{
			_putchar(*start);
			count++;
		}
		start++;
	}

	return (count);
}

/**
 * print_rev - Print a reversed string
 * @ap: va_list containing the string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_rev(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	str += _strlen(str) - 1;

	while (str >= 0)
	{
		_putchar(*str);
		str--;
		count++;
	}

	return (count);
}

/**
 * print_rot13 - Print a string using the ROT13 encryption
 * @ap: va_list containing the string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_rot13(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *original = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13ed = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		char *found = strchr(original, *str);

		if (found)
		{
			_putchar(rot13ed[found - original]);
			count++;
		}
		else
		{
			_putchar(*str);
			count++;
		}

		str++;
	}

	return (count);
}
