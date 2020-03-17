#include <stdio.h>
#include <unistd.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 *
 *
 *
 *
 */

int (*get_fun(const char *format))(va_list functions)
{
	int iter;
	selecFunc group[] = 
{
	{"c", print_char},
	{"s", print_string},
	{"NULL", NULL}
};

	for(iter = 0; group[iter].type != NULL; iter++)
	{
		if (*(group[iter].type) == *format)
		{
			return (group[iter].f);
		}	
	}
	return (0);
}

