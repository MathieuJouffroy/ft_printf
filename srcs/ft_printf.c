#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fd = 1;
	pf.format = (char*)format;
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			if (!*pf.format)
				break ;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
		{
			char_padding(&pf, *pf.format);
			pf.format++;
		}
	}
    return (end(&pf));
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fd = fd;
	pf.format = (char*)format;
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			if (!*pf.format)
				break ;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
		{
			char_padding(&pf, *pf.format);
			pf.format++;
		}
	}
    return (end(&pf));
}
