#include <stdio.h>
#include <unistd.h>
#include "holberton.h"
#include <stdlib.h>
/**
 *
 *
 *
 *
 */
int (*get_fun(const char format*)) (va_list functions)
{
	int iter;
	struct format[] = 
{
	{"c", print_char},
	{"s", print_string},
	{"NULL", NULL}
}
	for(iter = 0; format[iter].type != NULL; iter++)
	{
		if (format[iter].type == *s)
		{
			return (format[iter].f)
		}	
	}
	return (0);
}

