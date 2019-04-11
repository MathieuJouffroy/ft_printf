/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:58:02 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/11 21:27:37 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy((void*)dst, (const void*)src, ft_strlen(src) + 1);
	return (dst);
}
