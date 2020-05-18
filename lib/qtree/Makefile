##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libqtree.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I../../include/		\
			-I./../mynode/	\
			-g3		\

SRC	=	qtree_destroy.c	\
		rect_intersect.c	\
		hitbox_create.c	\
		qtree_rect_create.c	\
		qtree_recreate.c	\
		qtree_create.c		\
		qtree_subdivide.c	\
		qtree_draw.c		\
		qtree_push.c		\
		qtree_query.c		\
		qtree_collision.c	\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
