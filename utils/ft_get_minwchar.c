#include "../includes/ft_printf.h"

int		ft_get_minwchar(t_printf *pf, wchar_t *str, int len)
{
	int		c_len;
	int		j;
	int		cnt;
	int		prec;

	cnt = 0;
	j = 0;
    prec = len;
	while (*str && (len > 0))
	{
		c_len = w_charlen(*str);
		cnt += c_len;
		if (cnt <= prec)
			j += c_len;
		str++;
		len -= c_len;
	}
	return (pf->min_len - j < 0 ? 0 : pf->min_len - j);
}