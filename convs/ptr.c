/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:05 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/08 20:36:58 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_ptr_add(t_printf *pf)
{
	void	*ptr;
	int		len;

	ptr = (void *)va_arg(pf->ap, void *);
	len = ft_nbrlen((uintmax_t)ptr, B_HEX);
	pf->pad = pf->min_len - 2 - len;
	if (ptr == 0 && pf->precision == -1)
		hash_padding(pf);
	else
	{
        !(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
		hash_padding(pf);
        buffer(pf, ft_lltoa_base((uintmax_t)ptr, pf->base),len);
        (pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	}
}