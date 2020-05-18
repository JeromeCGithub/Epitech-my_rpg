/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** map header
*/

#ifndef __MAP_H__
#define __MAP_H__

#include <SFML/Graphics.h>

static const sfVector2u TILE_SIZE = {100, 100};

typedef enum tile_type_s {
    GRASS,
    ROAD,
    BRICK_1,
    BRICK_2,
    NB_TILE_TYPES,
    HOUSE,
    ROAD_1, ROAD_2, ROAD_3,
    ROAD_4, ROAD_5, ROAD_6,
    ROAD_7, ROAD_8, ROAD_9,
    ROAD_10, ROAD_11,
    ROAD_12, ROAD_13
} tile_type_t;

typedef struct tile_s {
    tile_type_t type;
    sfVector2i collisions;
    sfFloatRect bounds;
    sfRectangleShape *shape;
} tile_t;

typedef struct map_s {
    sfVector2u size;
    char const *filepath;
    tile_t **tiles;
} map_t;

static const char *TILE_TEXTURE[] = {
    "tile-grass",
    "tile-road-5",
    "tile-brick-1",
    "tile-brick-2",
    NULL,
    "tile-house",
    "tile-road-1",
    "tile-road-2",
    "tile-road-3",
    "tile-road-4",
    "tile-road-5",
    "tile-road-6",
    "tile-road-7",
    "tile-road-8",
    "tile-road-9",
    "tile-road-10",
    "tile-road-11",
    "tile-road-12",
    "tile-road-13"
};

static const int MASK_TYPE[] = {
    0b100000000, ROAD_1, 0b010000000, ROAD_2,
    0b111000000, ROAD_2, 0b011000000, ROAD_2,
    0b110000000, ROAD_2, 0b001000000, ROAD_3,
    0b000100000, ROAD_4, 0b100100100, ROAD_4,
    0b000100100, ROAD_4, 0b100100000, ROAD_4,
    0b010101010, ROAD_5, 0b000101010, ROAD_5,
    0b010001010, ROAD_5, 0b010100010, ROAD_5,
    0b010101000, ROAD_5, 0b000001000, ROAD_6,
    0b001001001, ROAD_6, 0b001001000, ROAD_6,
    0b000001001, ROAD_6, 0b000000100, ROAD_7,
    0b000000010, ROAD_8, 0b000000111, ROAD_8,
    0b000000011, ROAD_8, 0b000000110, ROAD_8,
    0b000000001, ROAD_9,  0b110100000, ROAD_10,
    0b010100000, ROAD_10, 0b111100000, ROAD_10,
    0b110100100, ROAD_10, 0b011100000, ROAD_10,
    0b010100100, ROAD_10, 0b011001000, ROAD_11,
    0b010001000, ROAD_11, 0b111001000, ROAD_11,
    0b011001001, ROAD_11, 0b110001000, ROAD_11,
    0b010001001, ROAD_11, 0b000100110, ROAD_12,
    0b000100010, ROAD_12, 0b000100111, ROAD_12,
    0b100100110, ROAD_12, 0b000100011, ROAD_12,
    0b100100010, ROAD_12, 0b000001011, ROAD_13,
    0b000001010, ROAD_13, 0b001001011, ROAD_13,
    0b000001111, ROAD_13, 0b001001010, ROAD_13,
    0b000001110, ROAD_13
};

static const char MAP_PATH[] = "save/map.data";
static const sfVector2u MAP_SIZE = {100, 100};
static const sfColor HOVER_COLOR = {200, 200, 200, 200};

_Bool map_init(char const *filepath, map_t *map);
_Bool map_generate(map_t *map);
void map_brush_click(void *view);
void map_brush_hover(void *view);
void map_inspect(map_t *map, sfBool reset);
void map_destroy(map_t *map);
void map_save(map_t *map, char const *filepath);
void map_set_tile(tile_t *tile);
void map_randomize(map_t *map, unsigned int seed);
void set_in_rect(sfFloatRect rect, sfVector2f *pos);

#endif /*__MAP_H__*/
