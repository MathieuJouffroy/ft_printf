/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:51:52 by pthan             #+#    #+#             */
/*   Updated: 2019/04/11 22:09:38 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*warning: flag ' ' is ignored when flag '+' is present [-Wformat] */
/* warning: flag '0' is ignored when flag '-' is present [-Wformat] */
/* => '+' > ' ' et '-' > '0' */
/* personal note : ' ' flag is ignored when flag '0' is present */
/* => '0' > ' ' */

#include "../includes/ft_printf.h"

/* renvoie -1 si il faut incrementer la partie entiere */
/* renvoie la precision arrondie sinon */

intmax_t		ft_getdecimal(long double nb, int n)
{
	intmax_t	res;
	int			i;

	i = 0;
	res = 0;
	nb = (nb - (intmax_t)nb) * 10;
	while (i++ < n)
	{
		res = res * 10 + (intmax_t)nb;
		nb = (nb - (intmax_t)nb) * 10;
	}
	if (nb >= 5)
		res++;
	if (res == pow_ten(10, n))
		return (-1);
	return (res);
}

/*
int				ft_floorlength(t_printf *pf, long double nb)
{
	int			nb_len;
	intmax_t	tmp;

	nb_len = 1;
	tmp = (intmax_t)nb;
	while (tmp >= 10)
	{
		tmp /= 10;
		nb_len++;
	}
	return (nb_len);
}
*/

void			ft_putllnbr(t_printf *pf, intmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		ft_putllnbr(pf, (nb / 10));
	char_padding(pf, (nb % 10 + 48));
}

void			ft_putdecimal(t_printf *pf, intmax_t decimal)
{
	int n;

	n = 0;
	if (decimal == -1)
	{
		while (n++ < pf->precision)
			char_padding(pf, '0');
	}
	else
		ft_putllnbr(pf, decimal);
}

static void		f_flags_padding(t_printf *pf, long double nb)
{
	if ((nb < 0) || !(1 / nb > 0))
		char_padding(pf, '-');
	if ((!(pf->flags & F_ZERO) && pf->flags & F_PLUS && nb >= 0)
		|| pf->flags & F_SPACE)
		(pf->flags & F_SPACE) ? char_padding(pf, ' ') : char_padding(pf, '+');
}

void			f_conv(t_printf *pf, long double nb)
{
	intmax_t	floor;
	intmax_t	decimal;

	f_flags_padding(pf, nb);
	decimal = (pf->precision) ? ft_getdecimal(nb, pf->precision) : 0;
	floor = (decimal == -1) ? (intmax_t)nb + 1 : (intmax_t)nb;
	ft_putllnbr(pf, floor);
	(pf->precision) ? char_padding(pf, '.') : 0;
	(pf->precision) ? ft_putdecimal(pf, decimal) : 0;
}

/*
void		float_conv(t_printf *pf)
{
	long double	nb;
	int			decimal;
	int			min;

	if (!pf->precision)
		pf->precision = 6;
	if (pf->precision == -1)
		pf->precision = 0;
	if ((pf->flags & LM_LONG))
		nb = (long double)va_arg(pf->ap, long double);
	else
		nb = (long double)va_arg(pf->ap, double);
	f_conv(pf, nb);
}
*/
