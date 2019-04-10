/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:41:28 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/10 16:58:54 by mjouffro         ###   ########.fr       */
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
		(!(pf->flags & F_MINUS)) && (!(pf->flags & F_ZERO)) ? min_padding(pf, ' ', pf->pad) : 0;
		((pf->conv == '%') && (pf->flags & F_ZERO)) ? min_padding(pf, '0', pf->pad) : 0;
		char_padding(pf, c);
		(pf->flags & F_MINUS) && (!(pf->flags & F_ZERO)) ? min_padding(pf, ' ', pf->pad) : 0;
	}
	else
		wchar_conv(pf);
}

void    wchar_conv(t_printf *pf)
{
	size_t wclen;
	wint_t	wc;

	wc = va_arg(pf->ap, wint_t);
	!(wclen = w_charlen(wc)) ? pf->ret = -1 : 0;
	pf->pad = pf->min_len ? pf->min_len - wclen : 0;
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	buffer(pf, ft_get_wchar(wc), wclen);
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
}

void	str_conv(t_printf *pf)
{
	char *str;
	int len;

	//(pf->flags & F_PLUS) ? (pf->flags &= ~F_PLUS) : 0;
   	//(pf->flags & F_SPACE) ? (pf->flags &= ~F_SPACE) : 0; 
	if (!((pf->flags & LM_LONG) || (pf->conv == 'S')))
	{
		str = va_arg(pf->ap, char*);
		len = str ? ft_strlen(str) : 6; // 6 for length of (null)
		if (pf->precision && pf->precision < len)
			len = (pf->precision == -1) ? 0 : pf->precision;
		pf->pad = pf->min_len ? pf->min_len - len : 0;
		!(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
		str ? buffer(pf, str, len) : buffer(pf, "(null)", len);
		(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	}
	else
		wstr_conv(pf);
}

void	wstr_conv(t_printf *pf)
{
	int wstrlen;
	wchar_t *wstr;
	int       len;
	int			i;

	i = 0;
	wstr = va_arg(pf->ap, wchar_t*);
	wstrlen = wstr ? ft_wstrlen(wstr) : 6;
	if (pf->precision && pf->precision < wstrlen)
		 wstrlen = pf->precision;
	len = wstr ? wslen_tobuff(wstr, wstrlen) : wslen_tobuff(L"(null)", wstrlen);
	pf->pad = (pf->min_len - len < 0) ? 0 : (pf->min_len - len);
	!(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	wstr ? wstr_tobuff(pf, wstr,  len) : buffer(pf, "(null)",  wstrlen);
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
}

size_t		wslen_tobuff(wchar_t *s, int wslen)
{
	int		to_buff;
	int 	c_len;
	int		cnt;
	int		tmp;

	cnt = 0;
	to_buff = 0;
	tmp = wslen;
	while (*s && (wslen > 0))
	{
		c_len = w_charlen(*s);
		cnt += c_len;
		if (cnt <= tmp)
			to_buff += c_len;
		wslen -= c_len;
		s++;
	}
	return (to_buff);
}