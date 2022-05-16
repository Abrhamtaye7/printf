#include "main.h"

/**
 * print_c - prints a character to the standard output.
 *
 * @ap: The argument parameter
 *
 * Return: Returns the number of characters to be printed.
 */
int print_c(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}

/**
 * print_s - prints the string to the standard output
 *
 * @ap: The argument parameter
 *
 * Return: Returns the number of characters to be printed.
 */

int print_s(va_list ap)
{
	int index = 0;

	const char *str =  va_arg(ap, const char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);
	for (; str[index]; index++)
		_putchar(str[index]);

	return (index);
}
