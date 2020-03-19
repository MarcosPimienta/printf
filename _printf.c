#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * _printf - prints almost ewverything that it gets sent to
 * @format: pointer that gets data to this script
 * @functions: list functions to the script in a variadic function
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list functions;
	int iptf = 0, len = 0;

	if (format == NULL)
	return (-1);
	va_start(functions, format);
	while (format && format[iptf] != '\0')
	{
		if (format[iptf] == '%')
		{
			if (format[++iptf]  == '%')
			{
			_putchar(format[iptf]);
			len++;
			}
			if (format[iptf] == 'c' || format[iptf] == 's'
				|| format[iptf] == 'd' || format[iptf] == 'i')
			{
				len = len + (*get_fun(&format[iptf]))(functions);
			}
			else
			{
				_putchar(format[--iptf]);
				len = len + 2;
			}

		}
		else if (format[iptf] == '%')
		{
			_putchar('%');
			_putchar(format[iptf]);
			len = len + 2;
		}
		else
		{
			_putchar(format[iptf]);
			len++;
		}
		iptf++;
	}
	va_end(functions);
	return (iptf);
}
