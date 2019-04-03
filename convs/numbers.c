#include "../includes/ft_printf.h"

int			int_conv(t_printf *pf, intmax_t nb)
{
	int		nb_len;
	int		min;
    uintmax_t new;

	new = treat_negaspos(pf, nb);
	nb_len = ft_nbrlen(new, pf->base);
    pf->precision ? (pf->flags &= ~F_ZERO) : 0;
	if (pf->precision == -1 && nb == 0)
		nb_len = 0;
	zero_flag(pf, nb_len);
	min = pf->min_len ? (pf->min_len - pf->pad - nb_len) : 0;
	if (pf->neg || pf->flags & F_PLUS || pf->flags & F_SPACE)	
		min--;
    (pf->precision == -1) ? (min = 0) : 0;

	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	padding(pf, nb_len);
	buffer(pf, ft_lltoa_base(new, pf->base), 0, nb_len);
	min < 0 ? (min = 0) : 0;
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	return (1);
}


int			u_conv(t_printf *pf, uintmax_t nb)
{
	int		nb_len;
	int		min;

	nb_len = ft_nbrlen(nb, pf->base);
    pf->precision ? (pf->flags &= ~F_ZERO) : 0;
	if (pf->precision == -1 && nb == 0)
		nb_len = 0;
	zero_flag(pf, nb_len);
	min = pf->min_len ? (pf->min_len - pf->pad - nb_len) : 0;
	if (pf->neg || pf->flags & F_PLUS || pf->flags & F_SPACE)	
		min--;
	(pf->precision == -1) ? (min = 0) : 0;

	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	min_padding(pf, '0', pf->pad);
	if (pf->conv == 'U')
		buffer(pf, to_upper(ft_lltoa_base(nb, pf->base)), 0, nb_len);
	else
		buffer(pf, ft_lltoa_base(nb, pf->base), 0, nb_len);
	min < 0 ? (min = 0) : 0;
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	return (1);
}

int		x_conv(t_printf *pf, uintmax_t nb)
{
	int		nb_len;
	int		min;

	nb_len = ft_nbrlen(nb, pf->base);
    pf->precision ? (pf->flags &= ~F_ZERO) : 0;
	if (pf->precision == -1 && nb == 0)
		nb_len = 0;
	zero_flag(pf, nb_len);
	min = pf->min_len ? (pf->min_len - pf->pad - nb_len) : 0;
	((pf->flags & F_HASH) && (nb != 0)) ? min -= 2 : 0;
	(pf->precision == -1) ? (min = 0) : 0;
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	check_xhash(pf, nb);
	min_padding(pf, '0', pf->pad);
	if (pf->conv == 'X')
		buffer(pf, to_upper(ft_lltoa_base(nb, pf->base)), 0, nb_len);
	else
		buffer(pf, ft_lltoa_base(nb, pf->base), 0, nb_len);
	min < 0 ? (min = 0) : 0;
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	return (1);
}

int		o_conv(t_printf *pf, uintmax_t nb)
{
	int		nb_len;
	int		min;

	nb_len = ft_nbrlen(nb, pf->base);
    pf->precision ? (pf->flags &= ~F_ZERO) : 0;
	if (pf->precision == -1 && nb == 0)
		nb_len = 0;
	zero_flag(pf, nb_len);
	min = pf->min_len ? (pf->min_len - pf->pad - nb_len) : 0;
	((pf->flags & F_HASH) && (nb_len >= pf->precision) && (nb != 0)) ? min-- : 0;
	(pf->precision == -1) ? (min = 0) : 0;
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	check_ohash(pf, nb);
	min_padding(pf, '0', pf->pad);
	if (pf->conv == 'O')
		buffer(pf, to_upper(ft_lltoa_base(nb, pf->base)), 0, nb_len);
	else
		buffer(pf, ft_lltoa_base(nb, pf->base), 0, nb_len);
	min < 0 ? (min = 0) : 0;
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	return (1);
}