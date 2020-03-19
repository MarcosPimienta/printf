#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdarg.h>

/**  Function printf **/
/**********************/

/**
 * struct selecFunc - structure to use in printf
 * @type: ooperator of structure
 * @f: function of work
 */


typedef struct selecFunc
{
	char *type;
	int (*f)(va_list);
} selecFunc;


int _printf(const char *format, ...);
int print_char(va_list functions);
int print_string(va_list functions);
int get_fun(const char *format, selecFunc group[], va_list functions);
int print_int(va_list list);
int putN(unsigned int n, unsigned int base, char *numbers);
int _putchar(char c);
int print_percent(__attribute__((unused))va_list ap);


#endif
