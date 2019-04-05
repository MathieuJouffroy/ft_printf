/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:41:28 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/05 16:25:01 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    char_conv(t_printf *pf)
{
	char c;

    (pf->flags & F_PLUS) ? (pf->flags &= ~F_PLUS) : 0;
   	(pf->flags & F_SPACE) ? (pf->flags &= ~F_SPACE) : 0;
	if (!((pf->flags & LM_LONG) || (pf->conv == 'C')))
	{
		c = (pf->conv == 'c') ? va_arg(pf->ap, int) : '%';
    	pf->precision = 0;
    	pf->pad = pf->min_len ? --pf->min_len : 0;
		if (!(pf->flags & F_MINUS))
			(pf->flags & F_ZERO) ? min_padding(pf, '0', pf->pad) 
			: min_padding(pf, ' ', pf->pad);
		char_padding(pf, c);
		(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	}
	else
		wchar_conv(pf);
}

void    wchar_conv(t_printf *pf)
{
	size_t wclen;
	wint_t	wc;

	wc = va_arg(pf->ap, wint_t);
	(!(wclen = w_charlen(wc))) ? pf->ret = -1 : 0;
	pf->pad = pf->min_len ? pf->min_len - wclen : 0;
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	buffer(pf, ft_get_wchar(wc), wclen);
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
}

/*
void	str_conv(t_printf *pf)
{
	char *str;
	int len;


    (pf->flags & F_PLUS) ? (pf->flags &= ~F_PLUS) : 0;
   	(pf->flags & F_SPACE) ? (pf->flags &= ~F_SPACE) : 0;
	str = va_arg(pf->ap, char*);
	len = str ? ft_strlen(str) : 0;
	(pf->precision == -1) ? 
}

void	wstr_conv(t_printf *pf)
{

}
