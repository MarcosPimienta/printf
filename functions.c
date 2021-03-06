#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
/**
* print_char - prints char at printf
* @functions: will feed what is called type
* Return: integer
*/
int print_char(va_list functions)
{
	int c = va_arg(functions, int);

	_putchar(c);
	return (1);
}

/**
* print_string - prints strings at printf
* @functions: as its name implies
* Return: integer
*/
int print_string(va_list functions)
{
	char *s;
	int iter = 0, count = 0;

	s = va_arg(functions, char *);
	if (s == NULL)
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
/**
* print_int - prints integers at printf
* @list: list of elements
*Return: integer
*/
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
/**
* putN - prints unsigned integers at printf
* @n: unsigned int
* @base: unsigned int
* @numbers: pointer to numbers.
*Return: integer
*/
int putN(unsigned int n, unsigned int base, char *numbers)
{
	int r = 1;

	if (n >= base)
	r += putN(n / base, base, numbers);
	_putchar(numbers[n % base]);
	return (r);
}
/**
 * print_percent - Print percent symbol
 * @functions: argumnt
 * Return: return the amount of characters
 */

int print_percent(__attribute__((unused))va_list functions)
{
	_putchar('%');
	return (1);
}
