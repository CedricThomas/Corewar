##
## Makefile for Makefile in /home/nicolas/libraries/lib_backup
##
## Made by Nicolas POLOMACK
## Login   <nicolas@epitech.net>
##
## Started on  Tue Nov  1 12:04:24 2016 Nicolas POLOMACK
## Last update Sun Apr  2 03:08:07 2017 Nicolas Polomack
##

SRC	=	is_a_num.c		\
		my_memset.c		\
		my_putstr.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putnbr_base.c	\
		my_strcmp.c		\
		my_strstr.c		\
		my_strlen.c		\
		my_strcpy.c		\
		my_strcat.c		\
		my_strcatdup.c		\
		my_strncat.c		\
		my_strncpy.c		\
		my_strncmp.c		\
		my_revstr.c		\
		my_getnbr.c		\
		my_getnbr_base.c	\
		my_find_prime_sup.c	\
		my_is_prime.c		\
		my_isneg.c		\
		my_power_rec.c		\
		my_sort_int_table.c	\
		my_square_root.c	\
		my_str_isalpha.c	\
		my_showmem.c		\
		my_showstr.c		\
		my_str_islower.c	\
		my_str_isprintable.c	\
		my_str_isnum.c		\
		my_str_isupper.c	\
		my_strcapitalize.c	\
		my_strlowcase.c		\
		my_strupcase.c		\
		my_swap.c		\
		my_strdup.c		\
		my_strndup.c		\
		my_printf.c		\
		my_puterror.c		\
		parsing.c		\
		my_strdup.c		\
		nb_args.c		\
		convert_base.c		\
		my_int_to_char.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I../../include -O3

all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	cp my.h ../../include
	cp libmy.a ..

clean:
##	@echo "------ CLEAN LIBMY.A ------"
	@rm -f $(OBJ)

fclean:	clean
##	@echo "----- FCLEAN LIBMY.A ------"
	@rm -f $(NAME)

re:	fclean all
