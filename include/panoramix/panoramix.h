/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define EPI_SUCCESS 0
#define EPI_FAILURE 84

/* Arguments positions */
#define NB_VILLAGERS 0
#define POT_SIZE 1
#define NB_FIGHTS 2
#define NB_REFILLS 3

/* Argument handling */
#define USAGE \
    "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n"
#define ARGS_REQUIRED 5
#define ARG_VALUE_ERROR "Panoramix: %s value must be > 0.\n"
#define ARG_TYPE_ERROR "Panoramix: %s value must be a number.\n"
#define VILLAGERS_ALLOC_ERROR "Panoramix: villagers could not be allocated.\n"

/* Villager messages */
#define VILLAGER_START "Villager %zu: Going into battle!\n"
#define VILLAGER_POTION \
    "Villager %zu: I need a drink... I see %zu servings left.\n"
#define VILLAGER_CALL "Villager %zu: Hey Pano wake up! We need more potion.\n"
#define VILLAGER_FIGHTING "Villager %zu: Take that roman scum! Only %zu left.\n"
#define VILLAGER_SLEEP "Villager %zu: I'm going to sleep now.\n"

/* Druid messages */
#define DRUID_START "Druid: I'm ready... but sleepy...\n"
#define DRUID_REFILL \
    "Druid: Ah! Yes, yes , I'm awake! Working on it! Beware I can only make " \
    "%zu more refills after this one.\n"
#define DRUID_SLEEP "Druid: I'm out of viscum. I'm going back to... zZz\n"

/* Structures */
typedef struct druid_s {
    size_t nb_refills;
    size_t pot_size;
    size_t pot_left;
    bool sleeping;
} druid_t;

typedef struct villager_s {
    size_t fights_left;
    ssize_t id;
    bool fighting;
} villager_t;

typedef struct panoramix_s {
    druid_t druid;
    villager_t *villagers;
    size_t nb_villagers;
} panoramix_t;
