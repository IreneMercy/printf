#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_char - Print a single character.
 * @arg: The character to print.
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Print a string.
 * @arg: The string to print.
 * Return: The number of characters printed.
 */
int print_string(va_list arg)
{
	char *s = va_arg(arg, char *);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		len++;
	}

	return (len);
}

/**
 * print_percent - Print a percent sign.
 * @arg: Unused.
 * Return: The number of characters printed (always 1).
 */
int print_percent(va_list arg)
{
	(void)arg;
	write(1, "%", 1);
	return (1);
}

/**
 * print_integer - print numbers
 * @arg: argument
 * Return: numbers to be printed
 */

int print_integer(va_list arg)
{
	int x = va_arg(arg, int);
	int d = 1, len = 0;

	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
		len++;
	}
	while (x / d >= 10)
		d *= 10;
	while (d != 0)
	{
		write(1, &("0123456789"[(x / d) % 10]), 1);
		len++;
		d /= 10;
	}
	return (len);
}

/**
 * print_binary - print unsigned integer to binary
 * @arg: unsigned integer to print
 * Return: integer printed
 */
int print_binary(va_list arg)
{
	unsigned int i = va_arg(arg, unsigned int);
	int len = 0;
	int bin_arr[32];
	int x;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (i > 0)
	{
		bin_arr[len] = i % 2;
		i /= 2;
		len++;
	}

	for (x = len - 1; x >= 0; x--)
	{
		write(1, &bin_arr[x], 1);
	}

	return (len);
}

/**
 * print_d - prints a decimal
 * @args: decimal argument
 * Return: counter
 */
int print_d(va_list args)
{
		return (print_integer(args));
}
