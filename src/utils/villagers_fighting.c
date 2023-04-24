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
    for (int i = 0; gauls[i].id >= 0; i++) {
        if (gauls[i].fighting)
            return true;
    }
    return false;
}
