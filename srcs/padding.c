#include "../includes/ft_printf.h"

void	char_padding(t_printf *pf, char c)
{
	check_buff(pf);
	pf->buff[pf->buff_i] = c;
	pf->buff_i++;
}

void	hash_padding(t_printf *pf)
{
	char_padding(pf, '0');
	check_buff(pf);
	if (pf->conv == 'x' || pf->conv == 'p')
		pf->buff[pf->buff_i++] = 'x';
	else if (pf->conv == 'X')
		pf->buff[pf->buff_i++] = 'X';
}

void	padding(t_printf *pf, int len)
{
	plus_flag(pf, len);
	(pf->flags & F_SPACE) ? char_padding(pf, ' ') : 0;
	pf->neg ? char_padding(pf, '-') : 0;
	min_padding(pf, '0', pf->pad);
}

void	min_padding(t_printf *pf, char c, int len)
{
	if (len > 0)
		while (len--)
			char_padding(pf, c);
}