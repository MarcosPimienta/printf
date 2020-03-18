#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdarg.h>

typedef struct selecFunc
{
	char *type;
	int (*f)(va_list);
} selecFunc;


int _printf(const char *format, ...);
int print_char(va_list functions);
int print_string(va_list functions);
int (*get_fun(const char *format))(va_list functions);
int print_int(va_list list);
int putN(unsigned int n, unsigned int base, char *numbers);
int _putchar(char c);

#endif
