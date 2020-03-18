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
 
        selecFunc group[] =
{
        {"c", print_char},
        {"s", print_string},
    {"d", print_int},
    {"i", print_int},
        {NULL, NULL}
};
 
    int igtfn = 0;
 
        while (group[igtfn].type != NULL)
        {
                if (*(group[igtfn].type) == *format)
                {
                        return (group[igtfn].f);
                }
                igtfn++;
        }
        return (0);
}
