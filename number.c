#include "main.h"

/**
 * convert - Convert a number to a given base
 * @num: The number to convert
 * @base: The base to convert to
 * @flags: Flags specifying conversion options
 * @params: Pointer to params_t struct
 *
 * Return: Pointer to the converted number string
*/
char *convert(long int num, int base, int flags)
{
	static char *representation = "0123456789ABCDEF";
	static char buffer[64];
	char *ptr;

	ptr = &buffer[63];
	*ptr = '\0';

	if (num == 0)
		return ("0");

	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}

	if (flags & CONVERT_UNSIGNED && *ptr == '0')
		ptr++;

	return (ptr);
}

/**
 * print_unsigned - Print an unsigned number
 * @ap: va_list containing the number to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_unsigned(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 10, CONVERT_UNSIGNED, params);
	int count = print_number(str, params);

	return (count);
}

/**
 * print_address - Print an address in hexadecimal
 * @ap: va_list containing the address to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_address(va_list ap, params_t *params)
{
	void *addr = va_arg(ap, void *);
	char *str = convert((unsigned long int)addr, 16, CONVERT_UNSIGNED, params);
	int count = print_number_right_shift(str, params);

	return (count);
}

/* more number-related functions here as needed */

