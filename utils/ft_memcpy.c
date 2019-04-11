/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:57:01 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/11 19:57:01 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (n--)
		*tmp++ = *(unsigned char*)src++;
	return (dest);
}
