#include "../includes/ft_printf.h"

int		end(t_printf *pf)
{
	pf->buff[pf->buff_i] = '\0';
	write(pf->fd, pf->buff, pf->buff_i);
	va_end(pf->ap);
	return (pf->ret + pf->buff_i);
}

void	reset_buff(t_printf *pf)
{
	write(pf->fd, pf->buff, BUFF_SIZE - 1);
	ft_bzero(pf->buff, BUFF_SIZE);
	pf->ret += (BUFF_SIZE - 1);
	pf->buff_i = 0;
}

void	check_buff(t_printf *pf)
{
	if (pf->buff_i == BUFF_SIZE - 1)
		reset_buff(pf);
}

int		buffer(t_printf *pf, char *str, int len)
{
	int i;

	i = 0;
	if (pf->buff_i + len >= BUFF_SIZE - 1)
	{
		ft_memcpy(&pf->buff[pf->buff_i], &str[i], ((BUFF_SIZE - 1) - pf->buff_i));
		i += (BUFF_SIZE - 1) - pf->buff_i;
		reset_buff(pf);
		buffer(pf, str, len);
	}
	else
		while (len--)
			pf->buff[pf->buff_i++] = str[i++];
	return (1);
}

void		wstr_tobuff(t_printf *pf, wchar_t *str, int len)
{
	int i;
	 
	i = 0;
	while (len > 0)
	{
		i = w_charlen(*str);
		buffer(pf, ft_get_wchar(*str), i);
		str++;
		len-= i;
	}
}
