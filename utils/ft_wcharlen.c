#include "../includes/ft_printf.h"

/*
**           UTF-8 encoding
**
** 0x7F     = max value for 1 byte  (8 bits)
** 0x7FF    = max value for 2 bytes (16 bits)
** 0xFFFF   = max value for 3 bytes (24 bits)
** 0x1FFFFF = max value for 4 bytes (32 bits)
*/

size_t		w_charlen(wint_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x1FFFFF)
		return (4);
	return (0);
}