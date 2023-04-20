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
