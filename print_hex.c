#include "main.h"

/**
 * helper_hex - helps the print_x function to print.
 *
 * @num: The number to be printed.
 * @type: The type of conversion.
 *
 * Return: Returns the number of characters that it prints.
 *
 */

int helper_hex(unsigned int num, int type)
{
	int ch_count = 0, rem;
	char hex_code;

	if (num / 16)
		ch_count += helper_hex(num / 16, type);

	rem = num % 16;
	if (rem > 9)
	{
		rem -= 10;
		if (type == 1)
			rem += 97;
		else if (type == 2)
			rem += 65;
		_putchar(rem);
		return (ch_count + 1);
	}

	_putchar(rem + '0');

	return (ch_count += 1);
}

/**
 * print_x - prints hexadecimal representation of a given number
 * in lowercase.
 *
 * @ap: The Argument parameter.
 *
 * Return: Returns the number of characters that it prints.
 */

int print_x(va_list ap)
{
	int ch_count = 0;
	unsigned int num = va_arg(ap, unsigned int);

	ch_count += helper_hex(num, 1);

	return (ch_count);
}

/**
 * print_X - prints hexadecimal representation of a given number
 * in uppercase.
 *
 * @ap: The argument parameter
 *
 * Return: Returns the number of characters that it prints.
 *
 */

int print_X(va_list ap)
{
	int ch_count = 0;
	unsigned int num = va_arg(ap, unsigned int);

	ch_count += helper_hex(num, 2);

	return (ch_count);
}

/**
 * print_S - prints custom conversion of string
 *
 * @ap: The argument parameter.
 *
 * Return: The number of characters printed by it.
 *
 */

int print_S(va_list ap)
{
	int ch_count, i = 0;
	char *str = va_arg(ap, char *);

	for (; *(str + i); i++)
	{
		if ((*(str + i) > 0 && *(str + i) < 32) || *(str + i) >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
				_putchar('0');

			_putchar(helper_hex(str[i], 2));

			ch_count += 1;
			continue;
		}

		_putchar(str[i]);
		ch_count += 1;
	}

	return (ch_count);
}
