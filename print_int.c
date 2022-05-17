#include "main.h"

/**
 * print_int - prints integer number
 *
 * ap: The argument parameter
 *
 * Return: The number of characters to be printed.
 *
 */

int print_int(va_list ap)
{
	unsigned int ch_count = 0, i, rem, div = 1;

	int number = va_arg(ap, int);

	if (number < 0)
	{
		_putchar(45);
		number *= -1;
		ch_count += 1;
	}

	for (i = 0; number / div > 9; i++, div *= 10)
		;
	for (; div >= 1; number %= div, div /= 10, ch_count++)
	{
		rem = number / div;
		_putchar(rem + '0');
	}

	return (ch_count);
}
