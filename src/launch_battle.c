/*
** EPITECH PROJECT, 2023
** src
** File description:
** launch_battle
*/

#include <panoramix/panoramix.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>

static panoramix_t *pano = NULL;
static pthread_mutex_t potion = {0};

static void *villager_battling(void *_ind)
{
    size_t ind = (size_t)_ind;

    printf(VILLAGER_START, ind);
    while (pano->villagers[ind].fights_left > 0) {
    }
    printf(VILLAGER_SLEEP, ind);
    return NULL;
}

static void *druid_sleeping(void __attribute__((unused)) * data)
{
    printf(DRUID_START);
    while (pano->druid.nb_refills > 0 && pano->druid.pot_left > 0) {
    }
    printf(DRUID_SLEEP);
    return NULL;
}

int launch_battle(panoramix_t *infos)
{
    pthread_t tid[infos ? infos->nb_villagers + 1 : 0];

    if (!(pano = infos))
        return EPI_FAILURE;
    pthread_mutex_init(&potion, NULL);
    if (pthread_create(tid, NULL, &druid_sleeping, NULL) < 0)
        return EPI_FAILURE;
    for (size_t i = 1; i <= pano->nb_villagers; i++)
        if (pthread_create(&tid[i], NULL, &villager_battling, (void *)i) < 0)
            return EPI_FAILURE;
    for (size_t i = 0; i <= pano->nb_villagers; i++)
        pthread_join(tid[i], NULL);
    return EPI_SUCCESS;
}
