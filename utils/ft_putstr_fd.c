#include "../includes/ft_printf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s != '\0')
		write(fd, s, ft_strlen(s));
}
