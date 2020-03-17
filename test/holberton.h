#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
typedef struct selecFunc
{
	char *type;
	int (*f)(va_list);
}slct_t;


int _printf(const char *format, ...);


#endif
