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
 * _printf - Print formatted output to stdout.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list arg;
	const char *p;
	int len = 0;

	va_start(arg, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;

			switch (*p)
			{
				case 'c':
					len += print_char(arg);
					break;
				case 's':
					len += print_string(arg);
					break;
				case '%':
					len += print_percent(arg);
					break;
				default:
					write(1, "%", 1);
					write(1, &(*p), 1);
					len += 2;
			}
		}
		else
		{
			write(1, &(*p), 1);
			len++;
		}
	}

	va_end(arg);

	return (len);
}
