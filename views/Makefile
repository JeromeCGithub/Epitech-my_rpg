##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libviews.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./../include	\

SRC	=	menu/index.c	\
		menu/actions.c	\
		game/exts.c	\
		game/index.c	\
		game/actions.c	\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
