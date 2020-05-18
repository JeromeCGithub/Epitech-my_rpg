##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libfps.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./		\

SRC	=	fps_set_position.c	\
		fps_create.c		\
		fps_draw.c		\
		fps_set_font.c		\
		fps_destroy.c		\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
