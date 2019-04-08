#include "../includes/ft_printf.h"

size_t	ft_wstrlen(wchar_t *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i += w_charlen(*s);
		s++;
	}
	return (i);
}