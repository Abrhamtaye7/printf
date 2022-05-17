#include "main.h"

/**
 * help_me - helper function for print int and it prints
 * an integer number.
 *
 * @num: The number to be printed.
 *
 * Return: Returns the number of characters printed by it.
 *
 */

int help_me(int num)
{
	int ch_count = 0;

	if (num / 10)
		ch_count += help_me(num / 10);

	_putchar((num % 10) + '0');
	return (ch_count += 1);
}

/**
 * print_int - prints an integer number to the standard output.
 *
 * @ap: The argument parameter.
 *
 * Return: Returns the number of characters printed by it.
 *
 */

int print_int(va_list ap)
{
	int ch_count = 0;
	int number = va_arg(ap, int);

	if (number < 0)
	{
		_putchar(45);
		number *= -1;
		ch_count += 1;
	}

	ch_count += help_me(number);

	return (ch_count);
}
