#include "main.h"

/**
 * print_hex - Print a number in hexadecimal base (lowercase)
 * @ap: va_list containing the number to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_hex(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 16, 0, params);
	int count = print_number(str, params);

	return (count);
}

/**
 * print_HEx - Print a number in hexadecimal base (uppercase)
 * @ap: va_list containing the number to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_HEx(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 16, CONVERT_LOWERCASE, params);
	int count = print_number(str, params);

	return (count);
}

/**
 * print_binary - Print a number in binary base
 * @ap: va_list containing the number to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_binary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 2, 0, params);
	int count = print_number(str, params);

	return (count);
}

/**
 * print_octal - Print a number in octal base
 * @ap: va_list containing the number to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_octal(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 8, 0, params);
	int count = print_number(str, params);

	return (count);
}
