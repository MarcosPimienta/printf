#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * _printf - prints almost ewverything that it gets sent to
 * @format: pointer that gets data to this script
 * Return: Always 0
 */
int _printf(const char *format, ...)
{

	selecFunc group[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"%", print_percent},
		{NULL, NULL}
		};

	va_list functions;
	int len = 0;

	if (format != NULL)
	{
		va_start(functions, format);
		len = get_fun(format, group, functions);
		va_end(functions);
	}
	else
	{
		return (-1);
	}

	return (len);
}
