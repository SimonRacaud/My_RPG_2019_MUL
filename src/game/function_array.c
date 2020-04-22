/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T11:21:15+02:00 | Author: simon
*/

#include "my_rpg.h"

FUNC_EXEC fct_exec[NB_GAME_STATE] = {
    NULL,
    NULL,
    &display_main_menu, // Main Menu
    &display_pause_menu, // Pause Menu
    NULL, // Fight Mode
    &display_main_world, // Main World
    &isow_run, // Iso World
    &display_option_menu // Option Menu
};

FUNC_EVENT fct_event[NB_GAME_STATE] = {
    NULL,
    NULL,
    &event_main_menu, // Main Menu
    &event_pause_menu, // Pause Menu
    NULL, // Fight Mode
    &event_main_world, // Main World
    &isow_event_manager, // Iso World
    &event_option_menu // Option Menu
};
