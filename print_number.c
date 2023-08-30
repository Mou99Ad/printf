#include "main.h"

/**
 * _isdigit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
*/
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string
 *
 * Return: The length of the string
*/
int _strlen(char *s)
{
	int length = 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * print_number - Print a number with optional left shift
 * @str: The number string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_number(char *str, params_t *params)
{
	int count = 0;

	if (params->minus_flag)
		count += _puts(str);

	if (params->width > _strlen(str))
		count += print_from_to(" ", str, NULL);

	if (!params->minus_flag)
		count += _puts(str);

	return (count);
}

/**
 * print_number_right_shift - Print a number with right shift
 * @str: The number string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_number_right_shift(char *str, params_t *params)
{
	int count = 0;

	if (params->width > _strlen(str))
		count += print_from_to(" ", str, NULL);

	count += _puts(str);

	return (count);
}

/**
 * print_number_left_shift - Print a number with left shift
 * @str: The number string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_number_left_shift(char *str, params_t *params)
{
	int count = 0;

	count += _puts(str);

	if (params->width > _strlen(str))
		count += print_from_to(" ", str, NULL);

	return (count);
}
