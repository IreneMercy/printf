#ifndef HEADER_FILE
#define HEADER_FILE

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);
unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_hex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_Hex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
#endif