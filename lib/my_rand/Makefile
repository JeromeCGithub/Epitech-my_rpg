##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libmy_rand.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./		\
			-g		\

SRC	=	my_rand.c	\
		perlin.c	\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
