#include "main.h"
/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: The arguments to be printed
 *
 * Return: The number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	params_t params = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			get_modifier((char *)&format[i], &params);
			get_flag((char *)&format[i], &params);
			get_width((char *)&format[i], &params, args);

			specifier_t specifiers[] = {
				{"c", print_char},
				{"s", print_string},
				{"%", print_percent},
				{NULL, NULL}
			};

			for (int j = 0; specifiers[j].specifier != NULL; j++)
			{
				if (*(specifiers[j].specifier) == format[i])
				{
					count += specifiers[j].f(args, &params);
					break;
				}
			}

			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
