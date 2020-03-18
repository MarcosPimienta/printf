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
int print_string(va_list functions)
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
int print_int(va_list list)
{
    int n = va_arg(list, int);
    int len = 0;
    unsigned int num;
 
    if (n < 0)
    {
        _putchar('-');
        len++;
        num = n * -1;
    }
    else
    {
        num = n;
    }
    len += putN(num, 10, "0123456789");
    return (len);
}
int putN(unsigned int n, unsigned int base, char *numbers)
{
    int r = 1;
 
    if (n >= base)
        r += putN(n / base, base, numbers);
    _putchar(numbers[n % base]);
    return (r);
}


