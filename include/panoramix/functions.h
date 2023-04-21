/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** functions
*/

#pragma once

#include <panoramix/panoramix.h>

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

/* argument handling */
int parse_args(panoramix_t *pano, int argc, char *const argv[]);

/* program */
int launch_battle(panoramix_t *pano);
