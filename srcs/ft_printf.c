/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:32:47 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/09 19:52:57 by mjouffro         ###   ########.fr       */
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
			color_or_char(&pf);
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
			color_or_char(&pf);
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

void    color_or_char(t_printf *pf)
{
	int	to_buff;

	if (*pf->format == '{')
	{
		if (!(color(pf) == NULL))
		{
			to_buff = (color(pf) == C_BOLD || color(pf) == C_UNDERLINE) ? 4 : 5;
				buffer(pf, (color(pf)), to_buff);
			pf->format += pf->pad;
		}
		else
		{
			char_padding(pf, *pf->format);
			pf->format++;
		}
	}
	else
	{
		char_padding(pf, *pf->format);
		pf->format++;
	}
}

char			*color(t_printf *pf)
{
	if (ft_strncmp(pf->format, "{bold}", (pf->pad = 6)) == 0)
		return (C_BOLD);
	else if (ft_strncmp(pf->format, "{underline}", (pf->pad = 11)) == 0)
		return(C_UNDERLINE);
	else if (ft_strncmp(pf->format, "{black}", (pf->pad = 7)) == 0)
		return (C_BLACK);
	else if (ft_strncmp(pf->format, "{red}", (pf->pad = 5)) == 0)
		return (C_RED);
	else if (ft_strncmp(pf->format, "{green}", (pf->pad = 7)) == 0)
		return (C_GREEN);
	else if (ft_strncmp(pf->format, "{yellow}", (pf->pad = 8)) == 0)
		return (C_YELLOW);
	else if (ft_strncmp(pf->format, "{blue}", (pf->pad = 6)) == 0)
		return (C_BLUE);
	else if (ft_strncmp(pf->format, "{purple}", (pf->pad = 8)) == 0)
		return (C_PURPLE);
	else if (ft_strncmp(pf->format, "{cyan}", (pf->pad = 6)) == 0)
		return (C_CYAN);
	else if (ft_strncmp(pf->format, "{white}", (pf->pad = 7)) == 0)
		return (C_WHITE);
	else
		return (NULL);
}