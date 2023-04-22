#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/**
 * buffering - writes a buffer to stdoutput
 * @buffer: the buffer to write
 * @buff: pointer to the buffer index
 */
void buffering(char buffer[], int *buff)
{
	if (*buff > 0)
		/* write content of buffer*/
		write(1, &buffer[0], *buff);

	/* clear buffer so can be reused*/
	*buff = 0;
}
/**
 * _printf - custom printf implementation
 * @format: format string
 * @...: vardiac arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j, characters_printed = 0, buff = 0;
	char buffer[BUFF_SIZE];
	va_list args_list;

	va_start(args_list, format);

	/* loop through each character in format */
	for (i = 0; format && format[i]; i++)
	{
		/* if current character is not '%' add it to buffer */
		if (format[i] != '%')
		{
			buffer[buff++] = format[i];

			/* if buffer is full write it to sdoutput */
			if (buff == BUFF_SIZE)
				buffering(buffer, &buff);
			/* increment characters printed */
			characters_printed++;
		}
		else
		{
			buffering(buffer, &buff);
			i++;
			switch (format[i])
			{
				case 'c':
					j = va_arg(args_list, int);
					buffer[buff++] = (char)j;

					if (buff == BUFF_SIZE)
						buffering(buffer, &buff);
					characters_printed++;
					break;

				case 's':
					for (j = 0; format[i] && format[i] != '%'; i++, j++)
					{
					buffer[buff++] = format[i];
					if (buff == BUFF_SIZE)
						buffering(buffer, &buff);
					buffering(buffer, &buff);
					}
					i--;
					characters_printed += j;
					break;

				default:
					buffer[buff++] = '%';
					if (buff == BUFF_SIZE)
						buffering(buffer, &buff);
					buffer[buff++] = format[i];
					characters_printed += 2;
					break;
			}
		}
	}
	buffering(buffer, &buff);
	return (characters_printed);
	va_end(args_list);
}
