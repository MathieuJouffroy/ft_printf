/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:57:07 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/11 19:57:07 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char *tmp;

	tmp = s;
	while (len--)
		*tmp++ = c;
	return (s);
}
