#include "../includes/ft_printf.h"

char				*ft_lltoa_base(uintmax_t nb, intmax_t base)
{
	uintmax_t		nb_size;
	static char		str[22];
	char			*strbase;

	ft_bzero(str, 22);
	strbase = "0123456789abcdef";
	nb_size = ft_nbrlen(nb, base);
	str[nb_size] = '\0';
	while (nb_size--)
	{
		str[nb_size] = strbase[(nb % base)];
		nb /= base;
	}
	return (str);
}