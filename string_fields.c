#include "main.h"

/**
 * get_precision - Extract and set precision from format
 * @p: Format string pointer
 * @params: Pointer to params_t struct
 * @ap: va_list containing variadic arguments
 *
 * Return: The pointer to the updated format string
*/

char *get_precision(char *p, params_t *params, va_list ap)
{
	if (*p == '.')
	{
		p++;
		if (_isdigit(*p))
		{
			params->precision = atoi(p);
			while (_isdigit(*p))
				p++;
		}
		else if (*p == '*')
		{
			params->precision = va_arg(ap, int);
			p++;
		}
	}

	return (p);
}
