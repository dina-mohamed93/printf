#include "main.h"

/**
 *init_params - clears struct fields and rest buf
 *@params: the parameters struct
 *
 *@va:theargument pointer
 */
void init_params(params_t *params, va_list va)
{
	params->unsigned int = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->precision = UINT_max;
	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)va;



}
