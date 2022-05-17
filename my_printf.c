#include "main.h"

/**
 * map_specifiers - maps specifiers with their corresponding
 * functions.
 *
 * @c: The next character after %.
 * @ap: The argument parameter.
 *
 * Return: The corresponding function to the specifier
 *
 */

int map_specifiers(char c, va_list ap)
{
	int index = 0;

	converter func_cor[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_int},
		{"i", print_int},
		{"b", print_b},
		{"o", print_o},
		{"u", print_u},
		{"x", print_x},
		{"X", print_X},
		{"S", print_S},

		{NULL, NULL}
	};

	for (; func_cor[index].specifier != NULL; index++)
	{
		if (func_cor[index].specifier[0] == c)
			return (func_cor[index].func(ap));
	}

	return (0);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print. It may conatain directives
 *
 * Return: Returns the number of characters to be printed. (excluding the
 * null byte used to end output to strings). if it fails it returns -1.
 *
 */

int _printf(const char *format, ...)
{
	int ch_count = 0, spec = 0, i = 0;

	va_list ap;

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	for (; *(format + i) != '\0'; i++)
	{
		if (*(format + i) != '%')
		{
			_putchar(*(format + i));
			ch_count++;
			continue;
		}
		if (*(format + i + 1) == '%')
		{
			_putchar('%');
			ch_count++;
			i++;
			continue;
		}
		if (*(format + i + 1) == '\0')
			return (-1);
		spec = map_specifiers(*(format + i + 1), ap);

		if (spec == -1 || spec != 0)
			i++;
		if (spec > 0)
			ch_count += spec;
		if (spec == 0)
		{
			_putchar('%');
			ch_count++;
		}
	}
	va_end(ap);
	return (ch_count);
}
