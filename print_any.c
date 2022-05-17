#include "main.h"


/**
 * print_o - prints the unsigned octal format of the number.
 *
 * @ap: The argument parameter.
 *
 * Return: The number of characters printed by it.
 *
 */

int print_o(va_list ap)
{
        unsigned int ch_count = 0, i, rem, div = 1;

        unsigned int number = va_arg(ap, unsigned int);

        for (i = 0; number / div > 7; i++, div *= 8)
                ;
        for (; div >= 1; number %= div, div /= 8, ch_count++)
        {
                rem = number / div;
                _putchar(rem + '0');
        }

        return (ch_count);
}



/**
 * print_u - prints the unsigned decimal format of the number.
 *
 * @ap: The argument parameter.
 *
 * Return: The number of characters printed by it.
 *
 */

int print_u(va_list ap)
{
        unsigned int ch_count = 0, i, rem, div = 1;

        unsigned int number = va_arg(ap, unsigned int);

        for (i = 0; number / div > 9; i++, div *= 10)
                ;
        for (; div >= 1; number %= div, div /= 10, ch_count++)
        {
                rem = number / div;
                _putchar(rem + '0');
        }

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
        unsigned int ch_count = 0, i, rem, div = 1;

        unsigned int number = va_arg(ap, unsigned int);

        for (i = 0; number / div > 1; i++, div *= 2)
                ;
        for (; div >= 1; number %= div, div /= 2, ch_count++)
        {
                rem = number / div;
                _putchar(rem + '0');
        }

        return (ch_count);
}
