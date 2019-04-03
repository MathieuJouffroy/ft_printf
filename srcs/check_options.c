#include "../includes/ft_printf.h"

void		zero_flag(t_printf *pf, int nb_len)
{
	if (pf->flags & F_ZERO)
	{
		pf->pad = pf->precision ? pf->precision - nb_len :
				(pf->min_len - nb_len - pf->neg);
		if ((pf->flags & F_SPACE) && (pf->precision == 0))
			pf->pad--;
	}
	else
		pf->pad = pf->precision ? pf->precision - nb_len : 0;
	pf->pad = pf->pad < 0 ? 0 : pf->pad;
}


void	plus_flag(t_printf *pf, int nb_len)
{
	if (pf->flags & F_PLUS)
	{
		char_padding(pf, '+');
		if (nb_len >= pf->precision)
			pf->pad--;
	}
}

void	check_ohash(t_printf *pf, int nb)
{
	if ((pf->flags & F_HASH) && nb != 0)
	{
		hash_padding(pf);
		pf->pad--;
	}
}

void	check_xhash(t_printf *pf, int nb)
{
	if ((pf->flags & F_HASH) && nb != 0)
	{
		hash_padding(pf);
		pf->pad = pf->precision ? pf->pad : pf->pad - 2;
	}
}

/*
** Treat all numbers as positive
** If number is negative -> take out + and space flags and convert nbr
** Indicate in structure that nbr is negative
*/
uintmax_t	treat_negaspos(t_printf *pf, intmax_t nb)
{
    uintmax_t new;

	if (nb < 0)
	{
		(pf->flags &= ~F_PLUS) && (pf->flags &= ~F_SPACE);
		new = -nb;
		pf->neg = 1;
	}
	else
		new = nb;
	return (new);
}