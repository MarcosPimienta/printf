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
        int iptf = 0, len = 0;
        if (format == NULL)
                return (-1);
        va_start(functions, format);
        while (format && format[iptf] != '\0')
        {
                if(format[iptf] == '%')
                {
 
                    if (format[++iptf]  == '%')
                    {
                      _putchar(format[iptf]);
                      len++;
                    }
         	   len = len + (*get_fun(&format[iptf]))(functions);
   
         }
                else if (format[iptf] == '%')
                {
           /** len = len + (*get_fun(format[iptf + 1])) (functions);*/
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
	printf("----%d----\n", iptf);
        return (iptf);
}
