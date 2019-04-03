#include "../includes/ft_printf.h"

/* -------------- PT_FUNCT -------------- */

t_conv g_conv[] =
{
	{"dDi", &ft_castconvint}
};
	//	{"uUoOxX", &ft_castconvuox}
	//{"cC", &c_conv}
	//{"oOuUxX", castconvoux}
	//{"cC", &pf_char},
	//{"f", &float_conv},
	//{"sS", &&pf_putstr},
	//{"p", &print_ptr_add},
	//{"%", &perct_conv}

int		is_conv(t_printf *pf)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (find_conv(g_conv[i].c, pf->conv))
			return (i);
		i++;
	}
	return (-1);
}

int		conv_to_fct(t_printf *pf)
{
	int i;

	i = is_conv(pf);
	if (i != -1)
		g_conv[i].funct(pf);
	return (1);
}

int		get_conversion(t_printf *pf)
{
	if ((pf->conv = find_conv("sSpdDioOuUxXcCfFbB%M", *pf->format)) != 0)
	{
		pf->format++;
		if ((pf->conv == 'o') || (pf->conv == 'O'))
			pf->base |= B_OCT;
		else if ((pf->conv == 'x') || (pf->conv == 'X') || (pf->conv == 'p'))
			pf->base |= B_HEX;
		else if ((pf->conv == 'b') || (pf->conv == 'B'))
			pf->base |= B_BIN;
		else
			pf->base = B_DEC;
	}
	else
	{
		//no_specifiers(pf);
		return (0);
	}
	return (1);
}
