#include "../includes/ft_printf.h"

void    char_conv(t_printf *pf)
{
    int min;
	char c;
	

    (pf->flags & F_PLUS) ? (pf->flags &= ~F_PLUS) : 0;
   	(pf->flags & F_SPACE) ? (pf->flags &= ~F_SPACE) : 0;
	if (!((pf->flags & LM_LONG) || (pf->conv == 'C')))
	{
		c = va_arg(pf->ap, int);
    	pf->precision = 0;
    	min = pf->min_len ? --pf->min_len : 0;
		if (!(pf->flags & F_MINUS))
			(pf->flags & F_ZERO) ? min_padding(pf, '0', min) : min_padding(pf, ' ', min);
		char_padding(pf, c);
		(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	}
	else
		wchar_conv(pf);
}

void    wchar_conv(t_printf *pf)
{
	int min;
	int wclen;
	wint_t	wc;

	wc = va_arg(pf->ap, wint_t);
	wclen = w_charlen(wc);
	min = pf->min_len ? --pf->min_len : 0;
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	buffer(pf, ft_get_wchar(wc), wclen);
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
}
