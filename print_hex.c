#include "main.h"

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
	unsigned int ch_count = 0, i, rem, div = 1;
	unsigned int number = va_arg(ap, unsigned int);

	for (i = 0; number / div > 15; i++, div *= 16)
		;
	for (; div >= 1; number %= div, div /= 16, ch_count++)
	{
		rem = number / div;

		if (rem > 9)
		{
			rem -= 10;
			rem += 97;
			_putchar(rem);
			continue;
		}
		_putchar(rem + '0');
	}

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
	unsigned int ch_count = 0, i, rem, div = 1;
	unsigned int number = va_arg(ap, unsigned int);

	for (i = 0; number / div > 15; i++, div *= 16)
		;
	for (; div >= 1; number %= div, div /= 16, ch_count++)
	{
		rem = number / div;
		if (rem > 9)
		{
			rem -= 10;
			rem += 65;
			_putchar(rem);
			continue;
		}
		_putchar(rem + '0');
	}

	return (ch_count);
}

/**
 * help_S - helps the print_S function in counting and printing
 *
 * @number: The number to be converted into hexadecimal code
 *
 * Return: The number of characters printed by it.
 *
 */

int help_S(int number)
{
	unsigned int ch_count = 0, i, rem, div = 1;

	for (i = 0; number / div > 15; i++, div *= 16)
		;
	for (; div >= 1; number %= div, div /= 16, ch_count++)
	{
		rem = number / div;
		if (rem > 9)
		{
			rem -= 10;
			rem += 65;
			_putchar(rem);
			continue;
		}
		_putchar(rem + '0');
	}

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
	int ch_count = 0, i = 0;
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(nil)";
	if (*str == '\0')
		return (-1);

	for (; *(str + i); i++)
	{
		if ((*(str + i) > 0 && *(str + i) < 32) || *(str + i) >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
				_putchar('0');

			_putchar(help_S(str[i]));

			ch_count += 3;
		}

		_putchar(str[i]);
		ch_count += 1;
	}

	return (ch_count);
}
