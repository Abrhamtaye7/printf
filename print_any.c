#include "main.h"

/**
 * helper - prints the numbers based on the type
 *
 * @num: The number to be printed.
 * @type: Base of the resulting number
 *
 * Return: It returns the number of characters to be printed.
 *
 */

int helper(int num, int type)
{
	int ch_count = 0;

	if (num / type)
		ch_count += helper(num / type, type);

	_putchar((num % type) + '0');

	return (ch_count += 1);
}

/**
 * print_o - prints octal format of the number
 *
 * @ap: The argument parameter
 *
 * Return: The number of characters printed by it.
 *
 */

int print_o(va_list ap)
{
	int ch_count = 0;
	unsigned int num = va_arg(ap, unsigned int);

	ch_count += helper(num, 8);

	return (ch_count);
}


/**
 * print_u - prints decimal format of the number
 *
 * @ap: Argument parameter.
 *
 * Return: Returns the number of characters to be printed
 *
 */

int print_u(va_list ap)
{
	int ch_count = 0;
	unsigned int num = va_arg(ap, unsigned int);

	ch_count += helper(num, 10);

	return (ch_count);
}

/**
 * print_b - prints the binary format of the number.
 *
 * @ap: The argument parameter.
 *
 * Return: The number of characters printed by it.
 *
 */

int print_b(va_list ap)
{
	int ch_count = 0;
	unsigned int num = va_arg(ap, unsigned int);

	ch_count += helper(num, 2);

	return (ch_count);
}

