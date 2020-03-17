#include <limits.h>
#include <stdio.h>
#include "holberton.h"
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list functions;
	int iter;

	va_start(functions, format);
	while (format[iter] == '\0')
	{
		if(format[iter] != '%')
		{
			_putchar(format[iter]);
		}
		else if
		(format[i] == '%')
		{
			get_fun(format[i + 1], functions);
		}
	}


}
