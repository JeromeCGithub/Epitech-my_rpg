##
## EPITECH PROJECT, 2019
## rpg
## File description:
## Makefile
##

NAME = my_rpg

MAIN = src/main.c \

SRC	=	src/game/rpg.c					\
		src/mobs/mob_attack.c				\
		src/entity_draw.c				\
		src/sound.c					\
		src/player/player_attack.c			\
		src/player/player_attack_redirect.c		\
		src/mobs/mob_position.c			\
		src/mobs/mobs_init.c				\
		src/mobs/mob_delete.c				\
		src/mobs/update_mobs.c				\
		src/mobs/mob_draw.c				\
		src/items/item_create.c			\
		src/items/item_draw.c				\
		src/game/setup/game_initialise.c		\
		src/game/setup/game_initialise_objects.c	\
		src/game/collisions.c				\
		src/game/views_create.c			\
		src/game/views_destroy.c			\
		src/player/player_get_item.c			\
		src/player/player_create.c			\
		src/player/player_update.c			\
		src/player/player_interact.c			\
		src/player/player_add_xp.c			\
		src/player/interface/player_interface_create.c	\
		src/player/interface/player_interface_update.c	\
		src/player/quests/player_quests.c		\
		src/player/player_save.c			\
		src/player/player_position.c			\
		src/player/player_create_from_save.c		\
		src/player/player_sounds.c			\
		src/player/player_movement.c			\
		src/particles/particle_engine_create.c		\
		src/particles/particle_engine_render.c		\
		src/particles/particle_create.c		\
		src/particles/particle_static.c		\
		src/particles/particle_stray.c			\
		src/objects/objects_function.c			\
		src/map/map_init.c				\
		src/map/map_generate.c				\
		src/map/set_in_rect.c				\
		src/map/map_set_view.c				\
		src/map/map_draw.c				\
		src/map/map_brush.c				\
		src/map/map_save.c				\
		src/map/map_destroy.c				\
		src/map/map_inspect.c				\
		src/map/map_set_tile.c				\
		src/map/map_randomize.c			\
		src/weather/update_weather.c			\
		src/npcs/npc_create.c				\
		src/npcs/npc_draw.c				\
		src/npcs/npc_functions.c			\

UI	=	src/game/user_interface/ui_setup.c					\
		src/game/user_interface/ui_draw.c					\
		src/game/user_interface/ui_event.c					\
		src/game/user_interface/ui_save.c					\
		src/game/user_interface/inventory/setup/inventory_setup.c		\
		src/game/user_interface/inventory/inventory_draw.c			\
		src/game/user_interface/inventory/inventory_event.c			\
		src/game/user_interface/inventory/inventory_mouse_hover.c		\
		src/game/user_interface/inventory/inventory_add.c			\
		src/game/user_interface/inventory/objects/object_create.c		\
		src/game/user_interface/inventory/objects/object_load_list.c		\
		src/game/user_interface/inventory/objects/object_duplicate.c		\
		src/game/user_interface/inventory/objects/obj_find_by_id.c		\
		src/game/user_interface/inventory/inventory_add_by_id.c		\
		src/game/user_interface/inventory/setup/inventory_rc_menu_setup.c	\
		src/game/user_interface/inventory/inventory_rc_menu_event.c		\
		src/game/user_interface/inventory/inventory_delete_object.c		\
		src/game/user_interface/inventory/inventory_equipe.c			\
		src/game/user_interface/inventory/revert_stat.c			\
		src/game/user_interface/skill_tree/skill_tree_create.c			\
		src/game/user_interface/skill_tree/skill_tree_draw.c			\
		src/game/user_interface/skill_tree/skill_tree_event.c			\
		src/game/user_interface/skill_tree/function_effect.c			\
		src/game/user_interface/skill_bar/skill_bar_init.c			\
		src/game/user_interface/skill_bar/skill_bar_draw.c			\
		src/game/user_interface/skill_bar/skill_bar_hover.c			\
		src/game/user_interface/skill_bar/skill_bar_event.c			\

VIEWS	=	views/menu/index.c	\
		views/menu/actions.c	\
		views/menu/events.c	\
		views/game/exts.c	\
		views/game/index.c	\
		views/game/actions.c	\
		views/game/events.c	\
		views/settings/index.c	\
		views/settings/actions.c\
		views/map/exts.c	\
		views/map/index.c	\
		views/map/actions.c	\
		views/map/events.c	\
		views/bestiary/actions.c \
		views/bestiary/index.c \
		views/end/actions.c \
		views/end/index.c \
		views/htp/index.c \
		views/htp/actions.c \
		views/cinematic/index.c \
		views/cinematic/actions.c \
		views/over/index.c \
		views/over/actions.c \

CUTSCENE	=	src/cutescene/cutscene_draw.c\
				src/cutescene/cutscene_init.c\
				src/cutescene/cutscene_moove.c\

TESTS	=	tests/test_node_reverse.c	\
		tests/test_node_insert.c	\
		tests/test_node_size.c		\
		tests/test_my_str_merge.c	\
		tests/test_my_strdup.c		\
		tests/test_my_strndup.c	\
		tests/test_my_strcmp.c \
		tests/test_my_strncmp.c	\
		tests/test_my_strlen.c \
		tests/test_my_itoa.c \
		tests/test_my_atoi.c \
		tests/test_my_error.c \

OBJ = $(MAIN:.c=.o) $(SRC:.c=.o) $(UI:.c=.o) $(VIEWS:.c=.o) $(CUTSCENE:.c=.o)

CPPFLAGS	=	-I./include	\

LDFLAGS	=	-l csfml-graphics	\
			-l csfml-audio		\
			-l csfml-window	\
			-l csfml-system	\
			-lm			\

CC	?=	 gcc

LIBS	=	-L./engine -lengine		\
		-L./lib/qtree -lqtree		\
		-L./lib/fps -lfps		\
		-L./lib/myerror -lmyerror	\
		-L./lib/mynode -lmynode	\
		-L./lib/my_rand -lmy_rand	\
		-L./lib/mystdio -lmystdio	\
		-L./lib/mystring -lmystring	\

LIBS_PATH	=	./engine/		\
			./lib/qtree/		\
			./lib/fps/		\
			./lib/myerror/		\
			./lib/mynode/		\
			./lib/my_rand/		\
			./lib/mystdio/		\
			./lib/mystring/	\

LIB_COMPILE	=	for LIB in $(LIBS_PATH); do	\
				make -C $$LIB $(1);	\
			done				\


all:	 $(NAME)

$(NAME):	$(OBJ)
	$(call LIB_COMPILE)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(DEBUG) $(LDFLAGS)

debug:	CPPFLAGS += -g3
debug:	re

clean:
	$(RM) $(OBJ)
	$(RM) sources/*/*~ *#
	$(RM) *.gcda *gcno ./unit_tests

fclean: clean
	$(RM) $(NAME)

lib_clean:
	$(call LIB_COMPILE, fclean)
	$(call LIB_COMPILE, clean)

tests_run:
	$(CC) -o unit_tests $(TESTS) $(LIB) $(ENGINE) $(SRC) $(CFLAGS) -lcriterion --coverage
	./unit_tests

re: fclean all

compile_launch:	$(NAME)
	./my_rpg

.PHONY: all re clean fclean
