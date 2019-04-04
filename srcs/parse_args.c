#include "../includes/ft_printf.h"

/*
**      FLAGS
**
** if there is a -  it cancels the zero flag.
** if there is a + it cancels the sp flag.
** it there is a # add the prefix 0x for hexa for example
** pf->flags |= res     ----->  pf->flags = pf->flags | res
** pf->flags &= ~F_ZERO ----->  pf->flags = pf->flags & ~F_ZERO
** x |= (mask)
**      Bits that are set to 1 in the mask will be set to 1 in x.
**      Bits that are set to 0 in the mask will be unchanged in x.
** x &= (~mask)
**      Bits that are set to 1 in the mask will be set to 0 in x. 
**      Bits that are set to 0 in the mask will be unchanged in x.
** if flags has all  "# +-0" it will give : 11111      (see .h)
*/

void	get_flags(t_printf *pf)
{
	int res;

	while ((res = find_flag("# +-0", *pf->format)) && pf->format++)
		pf->flags |= res;
	((pf->flags & F_ZERO) && (pf->flags & F_MINUS)) ? pf->flags &= ~F_ZERO : 0;
	((pf->flags & F_PLUS) && (pf->flags & F_SPACE)) ? pf->flags &= ~F_SPACE : 0;
}
/*
**      Field Width
**
**  49 is ascii for 1 and 57 for 9
*/
void	get_min_len(t_printf *pf)
{
	if (*pf->format >= 48 && *pf->format <= 57)
		pf->min_len = MAX(ft_atoi(pf->format), 1);
	if (*pf->format == '*')
	{
		pf->format++;
		pf->min_len = va_arg(pf->ap, int);
		if (pf->min_len < 0)
			(pf->flags |= F_MINUS) && (pf->flags &= ~F_ZERO);
		pf->min_len = ABS(pf->min_len);
	}
    while (*pf->format >= 48 && *pf->format <= 57)
		pf->format++;
}

void	get_precision(t_printf *pf)
{
	if (*pf->format == '.')
	{
		pf->format++;
		pf->precision = MAX(ft_atoi(pf->format), -1);
    	if (*pf->format == '*')
		{
			pf->format++;
			pf->precision = va_arg(pf->ap, int);
            //if (pf->precision <= 0)
        }
		(*pf->format == '-' || *pf->format == '+') ? pf->format++ : 0;
        while (*pf->format >= 48 && *pf->format <= 57)
			pf->format++;
	}
}

/*
**      Length Modifier
**
** find_flag returns 1 << i  and buff_i starts at 0
** 1 << 0 to 1 << 4 concerns the flags "# +-0"
** res <<= 5 : to go to the Length Modifiers (h,l,L,j...)
** 32 == 2^5 -> 1 << 5 == LM_SHORT ('h')
** 64 == 2^6 -> 1 << 6 == LM_LONG ('l')
** the 2nd res <<= 5 : to go to 1 << 10 or 1 << 11 (hh,ll)
*/

void	get_length_modifier(t_printf *pf)
{
	int res;

	if ((res = find_flag("hlLjz", *pf->format)))
	{
		res <<= 5;
		pf->format++;
		if (((res == 32) && (*pf->format == 'h')) ||
			((res == 64) && (*pf->format == 'l')))
		{
			res <<= 5;
			pf->format++;
		}
		pf->flags |= res;
	}
}

int	parse_arg(t_printf *pf)
{
	get_flags(pf);
	get_min_len(pf);
	get_precision(pf);
	get_length_modifier(pf);
	if (!get_conversion(pf))
	{
		printf("did not get conversion\n");
		return (0);
	}
	conv_to_fct(pf);
	return (1);
}