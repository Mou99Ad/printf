#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/* Function prototypes */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size);

/* Function prototypes for printing */
// ... (print_char, print_string, print_percent, and other printing functions)

/* Function prototypes for handling format specifiers and sizes */
// ... (get_flags, get_width, get_precision, get_size, and other functions)

/* Function prototypes for utility functions */
// ... (is_printable, append_hexa_code, is_digit, and other utility functions)

#endif /* MAIN_H */

