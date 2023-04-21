/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse_args
*/

#include <panoramix/functions.h>
#include <panoramix/panoramix.h>
#include <stdlib.h>
#include <unistd.h>

static int arg_check_positive_int(char *const arg)
{
    for (unsigned int i = 0; arg[i]; i++) {
        if (arg[i] < '0' || arg[i] > '9')
            return print_error(ARG_TYPE_ERROR, arg);
    }
    if (atoi(arg) <= 0)
        return print_error(ARG_VALUE_ERROR, arg);
    return EPI_SUCCESS;
}

static void fill_infos(panoramix_t *const pano, char *const argv[])
{
    pano->nb_villagers = atoi(argv[0]);
    pano->pot_size = atoi(argv[1]);
    pano->nb_fights = atoi(argv[2]);
    pano->nb_refills = atoi(argv[3]);
    pano->pot_left = pano->pot_size;
}

int parse_args(panoramix_t *pano, int argc, char *const argv[])
{
    if (!argv || argc != ARGS_REQUIRED || !pano)
        return print_usage(STDERR_FILENO);
    for (unsigned int i = 1; i < ARGS_REQUIRED; i++) {
        if (arg_check_positive_int(argv[i]) != EPI_SUCCESS)
            return EPI_FAILURE;
    }
    fill_infos(pano, argv);
    return EPI_SUCCESS;
}
