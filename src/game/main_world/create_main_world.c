/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_main_world
*/

#include "my_rpg.h"

static const char *background = "asset/sprite/background.png";
static const char *hitbox = "asset/map/map.hitbox";
static const float SHIFT_POS = 0.2;

static int init_map(game_t *game)
{
    WMAIN->rect_init.top = 0;
    WMAIN->rect_init.left = 0;
    WMAIN->rect_init.width = 480;
    WMAIN->rect_init.height = 256;
    WMAIN->rect = game->wmain->rect_init;
    WMAIN->size_map = (sfVector2i){91, 92};
    WMAIN->map_max_pos_rect = (sfVector2i){992, 1232};
    WMAIN->size_map_pixel = (sfVector2i){1472, 1488};
    WMAIN->view = sfView_createFromRect((sfFloatRect){0, 0, game->w.width,
    game->w.height});
    if (WMAIN->view == NULL)
        return EXIT_ERROR;
    WMAIN->nb_zoom = 0;
    return EXIT_SUCCESS;
}

static int load_map_texture(game_t *game)
{
    game->wmain->texture = sfTexture_createFromFile(background, NULL);
    game->wmain->sprite = sfSprite_create();
    if (game->wmain->texture == NULL || game->wmain->sprite == NULL)
        return EXIT_ERROR;
    sfSprite_setScale(WMAIN->sprite, (sfVector2f){WMAIN->zoom, WMAIN->zoom});
    sfSprite_setPosition(game->wmain->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(game->wmain->sprite, game->wmain->texture, sfFalse);
    sfSprite_setTextureRect(game->wmain->sprite, game->wmain->rect);
    return EXIT_SUCCESS;
}

static int init_player(game_t *game)
{
    WMAIN->position_on_map.x = 43;
    WMAIN->position_on_map.y = 32;
    update_position_on_map(game);
    WMAIN->shift_pos = SHIFT_POS;
    WMAIN->is_player_move = false;
    return EXIT_SUCCESS;
}

static int create_clock(game_t *game)
{
    bool err = false;
    int value = GET_VAR_NBR(game, "PLAYER_MOVE_CLOCK", &err);

    if (err == true) {
        return EXIT_ERROR;
    }
    WMAIN->clock = sfClock_create();
    WMAIN->timer = 0;
    WMAIN->ms_loop = value;
    return EXIT_SUCCESS;
}

int create_main_world(game_t *game)
{
    game->wmain = malloc(sizeof(main_world_t));
    if (game->wmain == NULL)
        return EXIT_ERROR;
    WMAIN->zoom = 4;
    WMAIN->shift_rect = 16;
    if (init_map(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (load_map_texture(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (init_player(game) == EXIT_ERROR)
        return EXIT_ERROR;
    game->wmain->hitbox = my_read_file(hitbox);
    if (game->wmain->hitbox == NULL)
        return EXIT_ERROR;
    if (create_clock(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_xp_bar(game) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
