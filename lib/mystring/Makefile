##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libmystring.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./		\

SRC	=	my_strcat.c	\
		my_strlen.c	\
		my_strncmp.c	\
		my_str_merge.c	\
		my_strndup.c	\
		my_strdup.c	\
		string_chr.c	\
		my_strcmp.c	\
		string_split.c	\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
