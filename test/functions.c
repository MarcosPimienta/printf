#include "holberton.h"
/**
 *
 *
 *
 */
int print_char(va_list functions)
{
	char c = va_arg(function, char);
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

	s = va_arg(list, char *);
	if(s == NULL)
	{
		s = "(null)";
	}
	while (s[iter] != '\0')
	{
		_putchar(s[iter]);
		i++;
	}
	return (iter);
}
