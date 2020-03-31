/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "inventory_system.h"

static item_t **get_tab_inventory(size_t size)
{
    item_t **inventory;

    if (size <= 0)
        return NULL;
    inventory = malloc(sizeof(item_t *) * size);
    if (!inventory)
        return NULL;
    for (size_t i = 0; i < size; i++)
        inventory[i] = NULL;
    return inventory;
}

bool get_player_inventory(player_inventory_t *inv, env_t​ *env)
{
    bool err;

    inv->size = my_env_get_value_int​(env, "INVENTORY_SIZE", &err);
    if (err || inv->size <= 0)
        return false;
    inv->inventory = get_tab_inventory(inv->size);
    if (!inv->inventory)
        return false;
    inv->nb_item = 0;
    return true;
}