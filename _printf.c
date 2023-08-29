#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	const char *ptr;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++; /* Move past '%' */
			if (*ptr == '\0')
				break; /* End of format string */
			if (*ptr == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*ptr == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*ptr == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*ptr);
				count += 2;
			}
		}
		else
		{
			_putchar(*ptr);
			count++;
		}
	}

	va_end(args);

	return (count);
}
