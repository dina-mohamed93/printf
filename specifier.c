#include "main.h"
/**
 *get_specifier - finds the format function accordening to the chractar
 *@s: the format string
 *
 *
 *Return: the number of bytes
 */
int (*get_specifier(char *s))(va_list va, par_t *patams)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"s", print_s},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	int j = 0;

	while (specifiers[j].specifier)
	{
		if (*s == apecifiers[j].specifier[0])
		{
			return (specifiers[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 *get_print_function - find the format function
 *@s:the format string
 *@va: argument pointer
 *@params : the parameters struct
 *
*return: the number of bytes
*
*/
int get_print_function(char *s, va_list va, par_t *params)
{
	int (*f)(va_list, par_t *) = get_specifier(s);

	if (f)
		return (f(va, params));
	return (0);
}
/**
*get_flag - finds the flag function
*@s: the format string
*@params: the parameters struct
*return: if flag was valid
*/
int get_flag(char *s, par_t *params)
{
	int x = 0;

	switch (*s)
	{
		case '+':
			x = params->plus_flag = 1;
			break;
		case ' ':
			x = params->space_flag = 1;
			break;
		case '-':
			x = params->minus_flag = 1;
			break;
		case '#':
			x = params->hasshtag = 1;
			break;
		case '0':
			x = params->zero_flag = 1;
			break;

	}
	return (i);
}
/**
*get_modifier - finds the modifier function
*@s: the format string
*@params: tha parameters
*return: if modifier was valid
*/
int get_modifier(char *s, par_t *params)
{
	int x = 0;

	switch (*s)
	{
	case 'h':
		x = params->h_modifier = 1;
		break;
	case 'h':
		x = params->l_modifier = 1;
		break;
	}
	return (i);
}
/**
*get_width - gets the width from the format string
*@s: the format string
*@params: the parameters struct
*@va: the argument pointer
*return: new pointer 
*/
char *get_width(char *s, par_t *params, va_list va)
{
	int r = 0;

	if (*s == '*')
	{
		r = va_arg(va, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
		r = r * 10 + (*s++ - '0');
	}
	params->width = r;
	return (s);
}
