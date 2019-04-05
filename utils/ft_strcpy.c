#include "../includes/ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy((void*)dst, (const void*)src, ft_strlen(src) + 1);
	return (dst);
}