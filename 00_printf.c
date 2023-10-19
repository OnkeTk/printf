#include <stdio.h>
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

		va_start(args, format);

		for (p = format; *p != '\0'; p++)
		{
			if (*p == '%')
			{
				p++;
				if (*p == '%')
					count += write(1, "%", 1);
				else if (*p == 'c')
					count += write(1, (char*)&(va_arg(args, int)), 1);
				else if (*p == 's')
				{
					if (char *s = va_arg(args, char*); char *s != '\0'; s++)
						count += write(1, s, 1);
				}
				else
				{
					count += write(1, "%", 1);
					count += write(1, p, 1);
				}
			}
			else
			{
				count += write(1, p, 1);
			}
		}
		va_end(args);
		return (count);
}
