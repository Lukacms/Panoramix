/*
** EPITECH PROJECT, 2023
** src
** File description:
** launch_battle
*/

#include <panoramix/functions.h>
#include <panoramix/panoramix.h>
#include <pthread.h>
#include <semaphore.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static druid_t druid = {0};
static villager_t *villagers = NULL;
static pthread_mutex_t potion;
static sem_t *sem;
static bool to_wake = false;

static void drink_potion(size_t ind)
{
    pthread_mutex_lock(&potion);
    if (druid.pot_left > 0) {
        printf(VILLAGER_POTION, ind, druid.pot_left);
        druid.pot_left -= 1;
        villagers[ind].fighting = true;
    } else if (druid.nb_refills > 0 && druid.sleeping && !to_wake) {
        printf(VILLAGER_POTION, ind, druid.pot_left);
        printf(VILLAGER_CALL, ind);
        to_wake = true;
    }
    pthread_mutex_unlock(&potion);
    if (villagers[ind].fights_left > 0 && druid.nb_refills == 0 &&
        druid.pot_left == 0) {
        printf(VILLAGER_SLEEP, ind);
        pthread_exit(NULL);
    }
}

static void *villager_battling(void *_ind)
{
    size_t ind = (size_t)_ind - 1;

    printf(VILLAGER_START, ind);
    sem_post(sem);
    while (villagers[ind].fights_left > 0) {
        if (villagers[ind].fighting) {
            villagers[ind].fights_left -= 1;
            printf(VILLAGER_FIGHTING, ind, villagers[ind].fights_left);
            villagers[ind].fighting = false;
            continue;
        }
        drink_potion(ind);
    }
    sem_wait(sem);
    printf(VILLAGER_SLEEP, ind);
    return NULL;
}

static void *druid_sleeping(void __attribute__((unused)) * data)
{
    printf(DRUID_START);
    while (druid.nb_refills > 0 || druid.pot_left > 0) {
        if (!villagers_fighting(villagers))
            break;
        pthread_mutex_lock(&potion);
        if (to_wake && druid.pot_left == 0 && druid.nb_refills > 0) {
            druid.pot_left = druid.pot_size;
            druid.nb_refills -= 1;
            printf(DRUID_REFILL, druid.nb_refills);
            to_wake = false;
            druid.sleeping = false;
        }
        if (druid.pot_left == 0)
            druid.sleeping = true;
        pthread_mutex_unlock(&potion);
    }
    printf(DRUID_SLEEP);
    return NULL;
}

int launch_battle(panoramix_t *infos)
{
    pthread_t tid[infos ? infos->nb_villagers + 1 : 0];

    if (!infos || !(sem = malloc(sizeof(sem_t))))
        return EPI_FAILURE;
    druid = infos->druid;
    villagers = infos->villagers;
    pthread_mutex_init(&potion, NULL);
    sem_init(sem, 0, 0);
    if (pthread_create(&tid[0], NULL, &druid_sleeping, NULL) < 0)
        return EPI_FAILURE;
    for (size_t i = 1; i <= infos->nb_villagers; i++)
        if (pthread_create(&tid[i], NULL, &villager_battling, (void *)i) < 0)
            return EPI_FAILURE;
    for (size_t i = 0; i <= infos->nb_villagers; i++)
        pthread_join(tid[i], NULL);
    pthread_mutex_destroy(&potion);
    sem_destroy(sem);
    return EPI_SUCCESS;
}
