#include "main.h"

/**
 * get_flag - Extract and set flags from format
 * @s: Format string pointer
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters consumed
*/

int get_flag(char *s, params_t *params)
{
	while (*s == '+' || *s == ' ' || *s == '#' || *s == '0' || *s == '-')
	{
		if (*s == '+')
			params->plus_flag = 1;
		else if (*s == ' ')
			params->space_flag = 1;
		else if (*s == '#')
			params->hashtag_flag = 1;
		else if (*s == '0')
			params->zero_flag = 1;
		else if (*s == '-')
			params->minus_flag = 1;
		s++;
	}
	return (s - format);
}

/**
 * get_modifier - Extract and set length modifiers from format
 * @s: Format string pointer
 * @params: Pointer to params_t struct
 *
 * Return: The number of characters consumed
*/

int get_modifier(char *s, params_t *params)
{
	if (*s == 'h')
		params->h_modifier = 1;
	else if (*s == 'l')
		params->l_modifier = 1;

	return (*s == 'h' || *s == 'l');
}

/**
 * get_width - Extract and set width from format
 * @s: Format string pointer
 * @params: Pointer to params_t struct
 * @ap: va_list containing variadic arguments
 *
 * Return: The number of characters consumed
*/

char *get_width(char *s, params_t *params, va_list ap)
{
	if (_isdigit(*s))
	{
		params->width = atoi(s);
		while (_isdigit(*s))
			s++;
	}
	else if (*s == '*')
	{
		params->width = va_arg(ap, int);
		s++;
	}

	return (s);
}
