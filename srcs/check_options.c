#include "../includes/ft_printf.h"

int		plus_flag(t_printf *pf, int len, int prec)
{
	if (pf->flags & F_PLUS)
	{
		char_padding(pf, '+');
		if (len >= pf->precision)
			prec -= 1;
	}
	return (prec);
}

int		check_ohash(t_printf *pf, int prec)
{
	if (pf->flags & F_HASH)
	{
		hash_padding(pf);
		prec -= 1;
	}
	return (prec);
}

int		check_xhash(t_printf *pf, int prec, int nb)
{
	if ((pf->flags & F_HASH) && nb != 0)
	{
		hash_padding(pf);
		prec = pf->precision ? prec : prec - 2;
	}
	return (prec);
}

int		zero_flag(t_printf *pf, int len)
{
	int prec;

	if (pf->flags & F_ZERO)
	{
		prec = pf->precision ? pf->precision - len :
				(pf->min_len - len - pf->neg);
		if ((pf->flags & F_SPACE) && (pf->precision == 0))
			prec -= 1;
	}
	else
		prec = pf->precision ? pf->precision - len : 0;
	prec = prec < 0 ? 0 : prec;
	return (prec);
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