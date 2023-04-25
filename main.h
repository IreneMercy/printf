#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);
int print_binary(va_list arg);
#endif
