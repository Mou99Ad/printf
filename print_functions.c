#include "main.h"

/**
 * print_char - Print a character
 * @ap: va_list containing the character to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_char(va_list ap, params_t *params)
{
	char c = va_arg(ap, int);
	int count = 0;

	if (params->width > 1 && !params->minus_flag)
		count += print_from_to(" ", &c, NULL);

	_putchar(c);
	count++;

	if (params->width > 1 && params->minus_flag)
		count += print_from_to(" ", &c, NULL);

	return (count);
}

/**
 * print_int - Print an integer
 * @ap: va_list containing the integer to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_int(va_list ap, params_t *params)
{
	int num = va_arg(ap, int);
	char *str = convert(num, 10, 0, params);
	int count = print_number(str, params);

	return (count);
}

/**
 * print_string - Print a string
 * @ap: va_list containing the string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	if (params->precision >= 0 && params->precision < _strlen(str))
	{
		char temp = str[params->precision];
		str[params->precision] = '\0';
		count = _puts(str);
		str[params->precision] = temp;
	}
	else
		count = _puts(str);

	return (count);
}

/**
 * print_percent - Print a percent sign
 * @ap: va_list (unused)
 * @params: Pointer to params_t struct (unused)
 *
 * Return: Always returns 1 (the number of characters printed)
*/
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;

	_putchar('%');
	return (1);
}

/**
 * print_S - Print a string with non-printable characters escaped
 * @ap: va_list containing the string to print
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters printed
*/
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += _printf("\\x");
			count += print_HEx_val(*str, 0);
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

/* more print functions here as needed */
