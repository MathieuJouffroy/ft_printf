/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:32:47 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/08 20:07:57 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fd = 1;
	pf.format = (char*)format;
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			if (!*pf.format)
				break ;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
		{
			char_padding(&pf, *pf.format);
			pf.format++;
		}
	}
	end(&pf);
    return (pf.ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fd = fd;
	pf.format = (char*)format;
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			if (!*pf.format)
				break ;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
		{
			char_padding(&pf, *pf.format);
			pf.format++;
		}
	}
	end(&pf);
    return (pf.ret);
}

void	reset_struct(t_printf *pf)
{
	pf->flags = 0;
	pf->precision = 0;
	pf->min_len = 0;
	pf->neg = 0;
	pf->base = 0;
	pf->conv = 0;
	pf->pad = 0;
}