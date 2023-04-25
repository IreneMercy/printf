#include "main.h"

unsigned int convert_hex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_Hex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_hex - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_hex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int number;
	unsigned int result = 0;
	char *real = "0x";

	if (len == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);
	if (len == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		result += _memcpy(output, real, 2);

	if (!(number == 0 && prec == 0))
		result += convert_ubase(output, number, "0123456789abcdef",
				flags, wid, prec);

	result += print_neg_width(output, result, flags, wid);

	return (result);
}

/**
 * convert_Hex - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_Hex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int number;
	unsigned int result = 0;
	char *real = "0X";

	if (len == LONG)
		number = va_arg(args, unsigned long);
	else
		number = va_arg(args, unsigned int);
	if (len == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		result += _memcpy(output, real, 2);

	if (!(number == 0 && prec == 0))
		result += convert_ubase(output, number, "0123456789ABCDEF",
				flags, wid, prec);

	result += print_neg_width(output, result, flags, wid);

	return (result);
}
