#include "../includes/ft_printf.h"

void		wchar_pad(t_printf *pf, wchar_t *str, int len)
{
	int		c_len;
	int		j;
	int		cnt;
	int		tmp;

	cnt = 0;
	j = 0;
    tmp = len;
	while (*str && (len > 0))
	{
		c_len = w_charlen(*str);
		cnt += c_len;
		if (cnt <= tmp)
			j += c_len;
		str++;
		len -= c_len;
	}
	pf->pad = (pf->min_len - j < 0) ? 0 : (pf->min_len - j);
}