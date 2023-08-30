#include "main.h"

/**
 * init_params - Initialize parameters struct
 * @params: Pointer to parameters struct to initialize
 * @ap: va_list containing variadic arguments
*/

void init_params(params_t *params, va_list ap)
{
	if (!params)
		return;

	params->unsign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->precision = 0;
	params->h_modifier = 0;
	params->l_modifier = 0;

    (void)ap;  /* va_list to prevent unused argument warning */
}
