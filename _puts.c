#include "main.h"

/**
 *_puts - prints a string with newline
 *@str: the string to print
 *
 *return: void
*
*/
void _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - s);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int j;
	static char buffer[OUTPUT_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= OUTPUT_BUFFER_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[j++] = c;
	return (1);
}
