##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libmystdio.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./		\

SRC	=	mystring_import.c	\
		pre_my_sprintf_i.c	\
		my_itoa.c		\
		my_private_sprintf.c	\
		my_putc.c		\
		pre_my_sprintf_c.c	\
		my_atoi.c		\
		my_sprintf.c		\
		my_puti.c		\
		my_puts.c		\
		pre_my_sprintf_s.c	\
		my_dprintf.c		\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
