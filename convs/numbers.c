#include "../includes/ft_printf.h"

int			int_conv(t_printf *pf, intmax_t nb)
{
	int		len;
	int		min;
	int		prec;
    uintmax_t new;

	new = treat_negaspos(pf, nb);
	len = ft_nbrlen(new, pf->base);
    pf->precision ? (pf->flags &= ~F_ZERO) : 0;
	if (pf->precision == -1 && nb == 0)
		len = 0;
	prec = zero_flag(pf, len);
	min = pf->min_len ? (pf->min_len - prec - len) : 0;
	if (pf->neg || pf->flags & F_PLUS || pf->flags & F_SPACE)	
		min -= 1;
    (pf->precision == -1) ? (min = 0) : 0;
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	padding(pf, prec, len);
	buffer(pf, ft_lltoa_base(new, pf->base), 0, len);
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	return (1);
}