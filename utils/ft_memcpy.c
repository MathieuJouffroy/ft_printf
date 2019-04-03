#include "../includes/ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (n--)
		*tmp++ = *(unsigned char*)src++;
	return (dest);
}
