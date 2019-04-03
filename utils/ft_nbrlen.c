#include "../includes/ft_printf.h"

int		ft_nbrlen(uintmax_t nb, intmax_t base)
{
	int				len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}