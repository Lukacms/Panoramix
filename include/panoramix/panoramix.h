/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix
*/

#pragma once

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#define EPI_SUCCESS 0
#define EPI_FAILURE 84

/* argument handling */
#define USAGE \
    "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n"
#define ARGS_REQUIRED 5
#define ARG_VALUE_ERROR "Panoramix: %d value must be > 0.\n"
#define ARG_TYPE_ERROR "Panoramix: %s value must be a number.\n"

/* Villager messages */
#define VILLAGER_START "Villager %d: Going into battle !\n"
#define VILLAGER_POTION \
    "Villager %d: I need a drink... I see %d servings left.\n"
#define VILLAGER_CALL "Villager %d: Hey Pano wake up ! We need more potion.\n"
#define VILLAGER_FIGHTING "Villager %d: Take that roman scum ! Only %d left.\n"
#define VILLAGER_SLEEP "Villager %d: I'm going to sleep now.\n"

/* Druid messages */
#define DRUID_START "Druid: I'm ready... but sleepy...\n"
#define DRUID_REFILL \
    "Druid: Ah! Yes, yes , I'm awake! Working on it! Beware I can only make " \
    "%d more refills after this one.\n"
#define DRUID_SLEEP "Druid: I'm out of viscum. I'm going back to... zZz\n"

/* print error messages */
static inline int print_usage(int stdfd)
{
    dprintf(stdfd, USAGE);
    return (stdfd == STDOUT_FILENO ? EPI_SUCCESS : EPI_FAILURE);
}

static inline int print_error(char *str, ...)
{
    va_list args = {0};

    va_start(args, str);
    dprintf(STDERR_FILENO, str, args);
    va_end(args);
    return EPI_FAILURE;
}

/*structures */
typedef struct panoramix_s {
    size_t nb_villagers;
    size_t pot_size;
    size_t pot_left;
    size_t nb_fights;
    size_t nb_refills;
} panoramix_t;
