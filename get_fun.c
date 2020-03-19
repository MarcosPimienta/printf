#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
/**
* get_fun - get functions
* @format: array of elements
* @functions: size of the array
 *@group: structure collections
* Return: Nothing.
*/
int get_fun(const char *format, selecFunc group[], va_list functions)
{
	int iptf = 0, ist, r = 0, len = 0;

	for ( ; format[iptf]; iptf++)
	{
		if (format[iptf] == '%')
		{
			for (ist = 0; group[ist].type != NULL; ist++)
			{
				if (format[iptf + 1]  == group[ist].type[0])
				{
					r = group[ist].f(functions);
					if (r == -1)
					{
						return (-1);
					}
					len += r;
					break;
				}
			}
			if (group[ist].type == NULL && format[iptf + 1] != ' ')
			{
				if (format[iptf + 1] != '\0')
				{
					_putchar(format[iptf]);
					_putchar(format[iptf + 1]);
					len = len + 2;
				}
				else
				return (-1);
			}
			iptf = iptf + 1;
		}
		else
		{
			_putchar(format[iptf]);
			len++;
		}
	}
	return (len);
}
