#include "../includes/ft_printf.h"

char		find_conv(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str[i]);
		i++;
	}
	return (0);
}
