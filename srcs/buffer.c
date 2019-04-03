#include "../includes/ft_printf.h"

void	reset_struct(t_printf *pf)
{
	pf->flags = 0;
	pf->precision = 0;
	pf->min_len = 0;
	pf->neg = 0;
	pf->base = 0;
	pf->conv = 0;
}

int		end(t_printf *pf)
{
	//va_end(pf->ap);
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

int		buffer(t_printf *pf, char *str, int i, int n)
{
	int len;

	len = n - i;
	if (pf->buff_i + len >= BUFF_SIZE - 1)
	{
		ft_memcpy(&pf->buff[pf->buff_i], &str[i], ((BUFF_SIZE - 1) - pf->buff_i));
		i += (BUFF_SIZE - 1) - pf->buff_i;
		reset_buff(pf);
		buffer(pf, str, i, n);
	}
	else
		while (len--)
			pf->buff[pf->buff_i++] = str[i++];
	return (1);
}