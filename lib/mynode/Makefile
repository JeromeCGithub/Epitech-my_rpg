##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libmynode.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./		\

SRC	=	node_insert.c		\
		node_free.c		\
		node_remove.c		\
		node_reverse.c		\
		node_insert_sorted.c	\
		node_pop.c		\
		node_size.c		\
		node_apply.c		\
		node_append.c		\
		node_filter.c		\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
