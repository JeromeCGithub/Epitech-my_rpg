##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libmyerror.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./		\

SRC	=	my_error.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
