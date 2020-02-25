# Executable
NAME 	= 	libftprintf.a

# Compilation
CC		= 	@cc -O3
CFLAGS	= 	-Wall -Wextra -Werror -Iincludes


SRCDIR = srcs/

UTILSDIR = utils/

CONVDIR = convs/

INCDIR = includes/

# Files && Objs

SRCS 	=		$(SRCDIR)ft_printf.c			\
				$(SRCDIR)buffer.c				\
				$(SRCDIR)parse_args.c			\
				$(SRCDIR)conv_specifiers.c		\
				$(SRCDIR)padding.c				\
				$(SRCDIR)check_flag_pad.c		\

CONV	=		$(CONVDIR)cast_nbrs.c			\
				$(CONVDIR)numbers.c				\
				$(CONVDIR)char_strings.c		\
				$(CONVDIR)pct_ptr.c				\
				$(CONVDIR)float.c				\
				$(CONVDIR)float_args.c			\

UTILS	=		$(UTILSDIR)ft_atoi.c			\
				$(UTILSDIR)ft_bzero.c			\
				$(UTILSDIR)find_conv.c			\
				$(UTILSDIR)find_flag.c			\
				$(UTILSDIR)ft_memcpy.c			\
				$(UTILSDIR)ft_memset.c			\
				$(UTILSDIR)ft_strncmp.c			\
				$(UTILSDIR)ft_strlen.c			\
				$(UTILSDIR)to_upper.c 			\
				$(UTILSDIR)ft_lltoa_base.c		\
				$(UTILSDIR)ft_nbrlen.c			\
				$(UTILSDIR)ft_wcharlen.c 		\
				$(UTILSDIR)ft_wstrlen.c 		\
				$(UTILSDIR)ft_get_wchar.c 		\
				$(UTILSDIR)maths.c 				\


UTIOBJ	= $(UTILS:.c=.o)

CONVOBJ	= $(CONV:.c=.o)

OBJ	    = $(SRCS:.c=.o)

# **************************************************************************** #

# SPECIAL CHARS

LOG_NOCOLOR		= \033[0m
LOG_GREEN		= \033[32m

# Protect

.PHONY:	all clean fclean re

# **************************************************************************** #

# RULES

# Main rules
all				: 	$(NAME)

re				: 	fclean all

# Compilation rules

#
#$(info $(OBJ) $(UTIOBJ) $(CONVOBJ))
$(NAME)			:	 $(OBJ) $(UTIOBJ) $(CONVOBJ)
					@ar rc $(NAME) $(OBJ) $(UTIOBJ) $(CONVOBJ)
					@ranlib $(NAME)
					@echo "Make $(NAME)$(LOG_GREEN) ✓ $(LOG_NOCOLOR)"
# Clean rules

clean			:
					@rm -rf $(OBJ) $(UTIOBJ) $(CONVOBJ)
					@echo "Removes all .o$(LOG_GREEN) ✓ $(LOG_NOCOLOR)"

fclean			: 	clean
					@rm -f $(NAME)

# **************************************************************************** #
