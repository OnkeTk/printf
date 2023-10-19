<<<<<<< HEAD
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Custom printf function to handle %c, %s, and %%
 * @format: format string
 * Return: number of characters printed(excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
		const char *p;

		for (*p = format, *p != '\0'; p++)
		{
			if (*p == '%')
			{
				p++;
				if (*p == '%')
					count += write(q, "%", 1);
				else if (*p == 'c')
					count += write(1, &va_arg(args, int), 1);
				else if (*p == 's')
					for (char *s = va_arg(args, char*); *s != '\0'; s++)
						count += write(1, s, 1);
				else
				{
					count += write(1, "%", 1);
				count += write(1, p, 1);
			}
		}
			else
			{
				count += wriet(1, p, 1);
			}
			va_end(args);
			return (count);
		}
=======
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
>>>>>>> 0312cdf31dcc30a10a8021792f619ff7420e5522
}
