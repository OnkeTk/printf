#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
* _printf - a function that handles conversion specifiers %c, %s, %%
* @format: is a character string
* Return: the number of characters printed
*/
int printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);
	while (format[i])
	{
	if (format[i] == '%')
	{
		i++;
	if (format[i] == 'c')
		{
	char c = (char)va_arg(args, int);
		putchar(c);
	} else if (format[i] == 'd')
	{
		int num = va_arg(args, int);

		if (num < 0)
		{
		putchar('-');
		num = -num;
	}
		printf("%d", num);
	}
	}
	else
	{
		putchar(format[i]);
	}
	i++;
	}
	va_end(args);
	return (i);
}
