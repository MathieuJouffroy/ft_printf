#include "../includes/ft_printf.h"

intmax_t		ft_atoi(char *s)
{
	int		sign;
	int		r;

	r = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? s++ : s;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return (sign * r);
}
