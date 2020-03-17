#include <limits.h>
#include <stdio.h>
#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list functions;
	int iter = 0;
	if (format == NULL)
		return (-1);
	va_start(functions, format);
	while (format[iter] == '\0')
	{
		if(format[iter] != '%')
		{
			_putchar(format[iter]);
		}
		else if
		(format[iter] == '%')
		{
			get_fun(format[iter], functions);
		}
	}


}
