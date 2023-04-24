/*
** EPITECH PROJECT, 2023
** arguments
** File description:
** fill_infos
*/

#include <panoramix/functions.h>
#include <panoramix/panoramix.h>
#include <stdbool.h>
#include <stdlib.h>

static villager_t *villagers_dna(int fights, int population)
{
    villager_t *villagers = malloc(sizeof(villager_t) * (population + 1));

    if (!villagers)
        return NULL;
    for (int i = 0; i < population; i++) {
        villagers[i].id = i;
        villagers[i].fighting = true;
        villagers[i].fights_left = fights;
    }
    villagers[population] = (villager_t){0};
    villagers[population].id = -1;
    return villagers;
}

static druid_t druid_dna(char *const argv[])
{
    druid_t druid = {0};

    druid.nb_refills = atoi(argv[NB_REFILLS]);
    druid.pot_size = atoi(argv[POT_SIZE]);
    druid.pot_left = druid.pot_size;
    return druid;
}

int fill_infos(panoramix_t *pano, char *const argv[])
{
    if (!pano || !argv || array_len(argv) != 4)
        return EPI_FAILURE;
    pano->druid = druid_dna(argv);
    pano->villagers =
        villagers_dna(atoi(argv[NB_FIGHTS]), atoi(argv[NB_VILLAGERS]));
    if (!pano->villagers)
        return print_error(VILLAGERS_ALLOC_ERROR, "");
    return EPI_SUCCESS;
}
