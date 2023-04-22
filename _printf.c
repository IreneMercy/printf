#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

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
				case 'd':
				case 'i':
					len += print_integer(arg);
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

