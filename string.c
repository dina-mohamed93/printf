#include "main.h"
/**
*get_precision - gets the precision from the format string
*@p:the format string
*@params: the parameters
*@va: the argument pointer
*
*return: new char  pointer 
*
*/
char *get_precision(char *p, par_t *params, va_list va)
{
	int t = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		t = va_arg(va, int);
		t++;
	}
	else
	{
		while (_isdigit(*p))
			t = t * 10 (*p++ - '0');
	}
	params->precision = t;
	return (p);
}
