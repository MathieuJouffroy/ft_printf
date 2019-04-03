#include "../includes/ft_printf.h"

int		find_flag(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1 << i);
		i++;
	}
	return (0);
}