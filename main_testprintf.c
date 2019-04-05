#include <stdio.h>
#include <stdlib.h>
#include "includes/ft_printf.h"
#include <locale.h>

int main (void)
{
	int nb;
	long int nb2;
	unsigned int unb;
	int nb0;
	int nbo;
	intmax_t nbmax;

	long long c;
	unsigned long int nb1;
	char *str;

	if (setlocale(LC_ALL, "") == NULL)
        printf("error while setlocale()\n");
	else
		printf("set done\n");
	nb = 1222921996;
	nb0 = 0;
	nb2 = 2147483647;
	nbmax = 9223372036854775807;
	nb1 = 4294967295;
	unb = 4294967295;
	nbo = -105192774;
	
	str = "salut";

	//printf("{% 5.c}\n", 0);
	//ft_printf("{% 5.c}\n", 0);
	/*printf("{%5c}\n", 0);
	ft_printf("{%5c}\n", 0);
	printf("{% 3c}\n", 0);
	ft_printf("{% 3c}\n", 0);
	printf("{%3c}\n", 0);
	ft_printf("{%3c}\n", 0);
	printf("{%-5.8c}\n", 'h');
	ft_printf("{%-5.8c}\n", 'h');
	printf("{%05.8c}\n", 'h');
	ft_printf("{%05.8c}\n", 'h');*/
	printf("42%lc42\n", (char)12150);
	ft_printf("42%lc42\n", (char)128150);
	printf("!%-32C!\n", (char)937);
	ft_printf("!%-32C!\n", (char)937);
	
/* ----------------------------------- D_TEST ------------------------------- */
	//printf("----- D_TEST -----\n");
	//printf("hash        :%#d\n", nb);  //undefined behavior
	//printf("%%+0-d      :%+0-d\n", nb); //flag '0' is ignored when flag '-' is present
	//printf("%%+0- d     :%+- d\n", nb); //flag ' ' is ignored when flag '+' is present

	//printf("%%+d        :%+d\n", nb);
	//printf("%%+0d       :%+0d\n", nb);
	//printf("%%0d        :%0d\n", nb);
	//printf("%%0.5d      :%0.5d\n", nb);
	//printf("%%010d      :%010d\n", nb);
	//printf("%%010.5d    :%010.5d\n", nb);0

/*
	printf("\n\n%- 30.0d:\n", -nb);
    ft_printf("%- 30.0d:\n", -nb);

	ft_printf("^.^/%060.48zd^.^/\n", (long)nb0);
	printf("^.^/%060.48zd^.^/\n", (long)nb0);

	printf("\n\n%- 30.0d:\n", -nb);
    ft_printf("%- 30.0d:\n", -nb);

	printf("\n\n% 30.0jd:\n", -nbmax);
    ft_printf("% 30.0jd:\n", -nbmax);

	printf("\n\n%0 30.-1jd:\n", nbmax);
    ft_printf("%0 30.-1jd:\n", nbmax);

	printf("\n\n% 30.3jd:\n", nbmax);
    ft_printf("% 30.3jd:\n", nbmax);

	printf("\n\n%+30.-1jd:\n", nbmax);
    ft_printf("%+30.-1jd:\n", nbmax);
	
	printf("\n\n% 2.30jd:\n", nbmax);
    ft_printf("% 2.30jd:\n", nbmax);

	printf("\n\n%0 2.30jd:\n", nbmax);
    ft_printf("%0 2.30jd:\n", nbmax);

	printf("\n\n% 2.30jd:\n", nbmax);
    ft_printf("% 2.30jd:\n", nbmax);

	printf("\n\n%+2.30jd:\n", nbmax);
    ft_printf("%+2.30jd:\n", nbmax);

	printf("\n\n%- 10.30jd:\n", nbmax);
    ft_printf("%- 10.30jd:\n", nbmax);


	printf("\n\n%- .30d:\n", nb);
    ft_printf("%- .30d:", nb);

	printf("\n\n%-034.30d:\n", nb0);
    ft_printf("%-034.30d:", nb0);

	printf("\n\n% -34.30d:\n", nb0);
    ft_printf("% -34.30d:", nb0);

	printf("\n\n%- 034.30d:\n", -nb0);
    ft_printf("%- 034.30d:", -nb0);

	printf("\n\n%+034.30ld:\n", -nb2);
   	ft_printf("%+034.30ld:", -nb2);

	printf("\n\n%15.34d:\n", nb0);
    ft_printf("%15.34d:", nb0);

	printf("\n\n%025d:\n", nb0);
    ft_printf("%025d:", nb0);

	printf("\n\n%-.4d:\n", nb0);
    ft_printf("%-.4d:", nb0);

	printf("\n\n%d:\n", nb0);
    ft_printf("%d:", nb0);

	printf("\n\n% 10.5d:\n", nb0);
    ft_printf("% 10.5d:", nb0);


	printf("\n\n%+10.5ld:\n", nb2);
    ft_printf("%+10.5ld:", nb2);

	printf("\n\n%+010ld:\n", nb2);
    ft_printf("%+010ld:", nb2);
	
	printf("\n\n%- 034.30ld:\n", nb2);
    ft_printf("%- 034.30ld:", nb2);

	printf("\n\n%-034.30ld:\n", nb2);
    ft_printf("%-034.30ld:", nb2);

	printf("\n\n% -34.30ld:\n", nb2);
    ft_printf("% -34.30ld:", nb2);

	printf("\n\n%- 034.30ld:\n", -nb2);
    ft_printf("%- 034.30ld:", -nb2);

	printf("\n\n%+034.30ld:\n", -nb2);
   	ft_printf("%+034.30ld:", -nb2);

	printf("\n\n%15.34ld:\n", nb2);
    ft_printf("%15.34ld:", nb2);

	printf("\n\n%025ld:\n", nb2);
    ft_printf("%025ld:", nb2);

	printf("\n\n%-.4ld:\n", nb2);
    ft_printf("%-.4ld:", nb2);

	printf("\n\n%ld:\n", -nb2);
    ft_printf("%ld:", -nb2);

	printf("\n\n%15.34ld:\n", -nb2);
    ft_printf("%15.34ld:", -nb2);

	printf("\n\n%025ld:\n", -nb2);
    ft_printf("%025ld:", -nb2);

	printf("\n\n%-.4ld:\n", -nb2);
    ft_printf("%-.4ld:", -nb2);

	ft_printf("hallo\n");

	printf("\n\n%-30.5u:\n", unb);
    ft_printf("\n%-30.5u:\n", unb);

	printf("\n\n%030.25lU:\n", nb1);
    ft_printf("%030.25lU:", nb1);

	printf("\n\n% -34.30lU:\n", nb1);
    ft_printf("% -34.30lU:", nb1);

	printf("\n\n%034.30lu:\n", -nb1);
   	ft_printf("%034.30lu:", -nb1);

	printf("\n\n%-34.30lU:\n", nb1);
    ft_printf("%-34.30lU:", nb1);

	printf("\n\n%-34.30lU:\n", -nb1);
    ft_printf("%-34.30lU:", -nb1);

	printf("\n\n%034.30lU:\n", -nb1);
    ft_printf("%034.30lU:", -nb1);

	printf("\n\n%15.34lU:\n", nb1);
    ft_printf("%15.34lU:", nb1);

	printf("\n\n%-34.30lU:\n", nb1);
    ft_printf("%-34.30lU:", nb1);

	printf("\n\n%034.30lU:\n", nb1);
    ft_printf("%034.30lU:", nb1);

	printf("\n\n%15.34lU:\n", nb1);
    ft_printf("%15.34lU:", nb1);

	printf("\n\n%034.30lU:\n", -nb1);
    ft_printf("%034.30lU:", -nb1);

	printf("\n\n%15.34lU:\n", nb1);
    ft_printf("%15.34lU:", nb1);

	printf("\n\n%-34.30lU:\n", nb1);
    ft_printf("%-34.30lU:", nb1);

	printf("\n\n%034.30lU:\n", nb1);
    ft_printf("%034.30lU:", nb1);

	printf("\n\n%15.34lU:\n", nb1);
    ft_printf("%15.34lU:", nb1);

	printf("\n\n%15.34o:\n", nb);
    ft_printf("%15.34o:", nb);

	printf("\n\n%-34.30o:\n", nb);
    ft_printf("%-34.30o:", nb);

	printf("\n\n%034.30o:\n", nb);
    ft_printf("%034.30o:", nb);

	printf("\n\n%15.34o:\n", nb);
    ft_printf("%15.34o:", nb);

	printf("\n\n!%#-2llo!:\n", (unsigned long long)nb0);
    ft_printf("!%#-2llo!:\n", (unsigned long long)nb0);

	printf("\n\n!%#-2.1llo!:\n", (unsigned long long)nb);
    ft_printf("!%#-2.1llo!:\n", (unsigned long long)nb);

	printf("\n\n%#15llo:\n", (unsigned long long)nb);
    ft_printf("%#15llo:\n", (unsigned long long)nb);


	printf("\n\n^.^/%#-o^.^/:\n", nbo);
    ft_printf("^.^/%#-o^.^/:\n", nbo);
	*/
    return (0);
}