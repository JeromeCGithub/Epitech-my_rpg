##
## EPITECH PROJECT, 2020
## engine
## File description:
## Makefile
##

NAME	=	libengine.a

CC	?=	gcc

CPPFLAGS	=	-Wall		\
			-Wextra	\
			-I./include	\

SRC	=	misc/ge_resources.c			\
		misc/ge_textures.c			\
		misc/ge_resources_load_from_file.c	\
		misc/ge_toolbox.c			\
		misc/ge_functions.c			\
		misc/ge_textures_load.c		\
		utils/ge_read_file.c			\
		utils/my_atof.c			\
		utils/ge_hovers.c			\
		utils/ge_parsers.c			\
		utils/ge_utils.c			\
		xml/ge_xml_form_widget.c		\
		xml/attrs/ge_btn_attrs.c		\
		xml/attrs/ge_btn_attrs2.c		\
		xml/attrs/ge_cbox_attrs.c		\
		xml/attrs/ge_pane_attrs.c		\
		xml/attrs/ge_attrs.c			\
		xml/attrs/ge_attrs_two.c		\
		xml/ge_xml_parse_attr.c		\
		xml/ge_xml_parse_tag.c			\
		xml/ge_xml_load_interface.c		\
		widget/ge_widget_render_view_widgets.c	\
		widget/ge_widget_free_widgets_array.c	\
		widget/ge_widget_create.c		\
		widget/ge_widget_get.c			\
		widget/ge_widget_update_button.c	\
		widget/ge_widget_update_cbox.c		\
		widget/ge_widget_get_position2.c	\
		widget/ge_widget_update_pane.c		\
		widget/ge_widget_get_position.c	\
		view/ge_view_run.c			\
		view/ge_view_create.c			\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all
