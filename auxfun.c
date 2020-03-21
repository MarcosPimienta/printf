#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
/**
 * decToBinary - Converts dec to binary
 * @list: list of arguments
 * Return: return the iterator
 */
int decToBinary(va_list list)
{
unsigned int bn = va_arg(list, unsigned int);
	int i = 0, j;
	char b[1000] = {'\0'};
		if (bn == 0)
		{
			_putchar('0');
			return (1);
		}
			while (bn > 0)
			{
			b[i] = bn % 2;
			bn /= 2;
			i++;
			}
		for (j = i - 1; j >= 0; j--)
		{
		_putchar(b[j] + '0');
		}
		return (i);
}
