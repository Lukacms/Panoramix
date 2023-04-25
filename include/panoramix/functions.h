/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** functions
*/

#pragma once

#include <panoramix/panoramix.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* print error messages */
static inline int print_usage(int stdfd)
{
    dprintf(stdfd, USAGE);
    return (stdfd == STDOUT_FILENO ? EPI_SUCCESS : EPI_FAILURE);
}

static inline int print_error(char *str, char *arg)
{
    dprintf(STDERR_FILENO, str, arg);
    return EPI_FAILURE;
}

/* argument handling */
int parse_args(panoramix_t *pano, int argc, char *const argv[]);
int fill_infos(panoramix_t *pano, char *const argv[], int argc);

/* program */
int launch_battle(panoramix_t *infos);

/* utils */
int array_len(const void *arr);
bool villagers_fighting(villager_t *gauls);
