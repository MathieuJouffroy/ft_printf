#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# include <float.h>
# include <sys/types.h>

# define BUFF_SIZE 128

# define ABS(Value) (Value < 0) ? -Value : Value
# define DABS(Value)(Value < 0.0f) ? -Value : Value
# define MAX(a, b)  a > b ? a : b
# define MIN(a, b)  a < b ? a : b
# define STRERR			strerror


/*
**-------------------------------- FLAGS & SPEC ----------------------------
*/

# define F_HASH  (1 << 0)   //  '#'    00001 = 1  
# define F_SPACE (1 << 1)  //  ' '    00010 = 2
# define F_PLUS  (1 << 2)   //  '+'    00100 = 4  // sign of number
# define F_MINUS (1 << 3)  //  '-'    01000 = 8  // left justify
# define F_ZERO  (1 << 4)    // '0'    10000 = 16

# define LM_SHORT  (1 << 5)  //  'h'  (di) short  int 	 /   (uox) unsigned short     int 
# define LM_LONG   (1 << 6)  //  'l'  (di) long 	 int 	 /   (uox) unsigned long      int
# define LM_DOUBLE (1 << 7)  //  'L'
# define LM_INTMAX (1 << 8)  //  'j' 	   intmax_t      /   uintmax_t
# define LM_SIZE_T (1 << 9)  //  'z'          size_t      /   ssize_t
# define LM_CHAR   (1 << 10) //  'hh'   signed char
# define LM_LONG2  (1 << 11) //  'll'  (di) long long  int /   (uox) unsigned long long int

/*
**----------------------------------- BASES -------------------------------
*/

# define B_DEC 10
# define B_BIN (1 << 1)
# define B_OCT (1 << 3)
# define B_HEX (1 << 4)

/*
**----------------------------------- COLORS -------------------------------
*/

# define C_NOCOLOR		"\033[0m"
# define C_BLACK		"\033[30m"
# define C_RED			"\033[31m"
# define C_GREEN		"\033[32m"
# define C_YELLOW		"\033[33m"
# define C_BLUE			"\033[34m"
# define C_PURPLE		"\033[35m"
# define C_CYAN			"\033[36m"
# define C_WHITE		"\033[37m"

/*
**----------------------------------- STRUCT -------------------------------
*/

typedef struct	s_printf
{
    int         ret;
    int         fd;
	int		    flags;
    int         min_len;
	int		    precision;
    int		    base;
    int         pad;
    int         neg;
    int		    buff_i;
	char	    buff[BUFF_SIZE];
	char	    *format;
    char        conv;
    va_list     ap;
}				t_printf;

int		ft_printf(const char *format, ...);

typedef  void(*t_f_conv)(t_printf*);


typedef struct	s_conv
{
	char		*c;
	t_f_conv	funct;
}				t_conv;

/*
**---------------------------------- PARSING -------------------------------
*/

int				parse_arg(t_printf *pf);

/*
**-------------------------------- CONVERSIONS -----------------------------
*/

void		    ft_castconvint(t_printf *pf);
void	        ft_castconvuox(t_printf *pf);
int		        is_conv(t_printf *pf);
int				conv_to_fct(t_printf *pf);
int				get_conversion(t_printf *pf);

/*
**-------------------------------- BUFF MANAGER ----------------------------
*/

void	reset_struct(t_printf *pf);
void	reset_buff(t_printf *pf);
void	check_buff(t_printf *pf);
int		buffer(t_printf *pf, char *str, int len);
int		end(t_printf *pf);
/*
**---------------------------------- PADDING -------------------------------
*/

void			hash_padding(t_printf *pf);
void			min_padding(t_printf *pf, char c, int len);
void			char_padding(t_printf *pf, char c);

/*
**----------------------------------- CHECK --------------------------------
*/

void				plus_flag_pad(t_printf *pf, int len);
void				zero_flag_pad(t_printf *pf, int len);
void				hash_flag_pad(t_printf *pf, int nb);

/*
**--------------------------------- NUMBERS -------------------------------
*/

void			int_conv(t_printf *pf, intmax_t nb);
void			uint_conv(t_printf *pf, uintmax_t nb);
void		    ox_conv(t_printf *pf, uintmax_t nb);
uintmax_t	    treat_negaspos(t_printf *pf, intmax_t nb);

/*
**---------------------------- CHAR & STRINGS -----------------------------
*/

void		char_conv(t_printf *pf);
void        wchar_conv(t_printf *pf);
void	    str_conv(t_printf *pf);

/*
**----------------------------------- UTILS -------------------------------
*/

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_putstr_fd(char const *s, int fd);
int		        ft_nbrlen(uintmax_t nb, intmax_t base);
int				find_flag(char *str, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*to_upper(char *str);
char		    find_conv(char *str, char c);
char	        *to_upper(char *str);
char		    *ft_lltoa_base(uintmax_t nb, intmax_t base);
char		    *ft_get_wchar(wint_t wc);
size_t		    w_charlen(wint_t wc);
size_t			ft_strlen(const char *str);
intmax_t		ft_atoi(char *s);
#endif