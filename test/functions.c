#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 *
 *
 *
 */
int print_char(va_list functions)
{
	int c = va_arg(functions, int);
	_putchar(c);
	return (1);
}

/**
 *
 *
 *
 */
int print_str(va_list functions)
{
	char *s;
	int iter = 0, count = 0;

	s = va_arg(functions, char *);
	if(s == NULL)
	{
		s = "(null)";
	}
	while (s[iter] != '\0')
	{
		_putchar(s[iter]);
		iter++;
		count++;
	}
	return (count);
}
