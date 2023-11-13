#include "main.h"

void print_buffer(char buffer[], int *bure_if);

/**
 * _print - Printf format
 * @format: function.
 * Return: always 0 when success.
 */

int _printf(const char *format, ...)
{
	int i, hello = 0 ,  hello_chars = 0;
	int red, wide, pre, bure_if = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format [i] != '\0' ; i++)
	{
		if (format[i] != '%')
		{
			buffer[bure_if++] = format[i];
			if (bure_if == BUFF_SIZE)
				print_buffer(buffer, &bure_if);
			hello_chars==;
		}

		else
		{
			print_buffer(buffer, &bure_if);
			red = get_red(format, &i);
			width = get_wide(format, &i, list);
			pre = get_pre(format, &i, list);
			size = get_size(format, &i);
			++i;
			hello = handle_hello(format, &i, list, buffer,
					red, wide, pre, size);
			if (hello == -1)
				return (-1);
			hello_chars += hello;
		}
	}

	print_buffer(buffer, &bure_if);

	va_end(list);

	return (hello_chars)
}

