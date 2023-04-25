/*
** EPITECH PROJECT, 2023
** utils
** File description:
** villagers_fighting
*/

#include <panoramix/panoramix.h>
#include <stdbool.h>

bool villagers_fighting(villager_t *gauls)
{
    if (!gauls)
        return false;
    for (int i = 0; gauls[i].id >= 0; i++) {
        if (gauls[i].fights_left > 0)
            return true;
    }
    return false;
}
