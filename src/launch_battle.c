/*
** EPITECH PROJECT, 2023
** src
** File description:
** launch_battle
*/

#include <panoramix/panoramix.h>

static panoramix_t *pano = NULL;

int launch_battle(panoramix_t *infos)
{
    pano = infos;
    if (!infos)
        return EPI_FAILURE;
    return EPI_SUCCESS;
}
