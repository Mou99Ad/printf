#include <stdio.h>
#include "main.h"
/**
 * main - Entry point for testing the _printf function.
 *
 * Return: Always 0
*/

int main(void)
{
	int len;

	len = _printf("Hello, %s!\n", "Mouad");
	_printf("Number of characters printed: %d\n", len);

	return (0);
}
