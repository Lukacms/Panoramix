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
    unsigned int ind = 0;

    if (arg[ind] == '-')
        ind++;
    while (arg[ind]) {
        if (arg[ind] < '0' || arg[ind] > '9')
            return print_error(ARG_TYPE_ERROR, arg);
        ind++;
    }
    if (atoi(arg) <= 0)
        return print_error(ARG_VALUE_ERROR, arg);
    return EPI_SUCCESS;
}

int parse_args(panoramix_t *pano, int argc, char *const argv[])
{
    if (!argv || argc != ARGS_REQUIRED || !pano)
        return print_usage(STDERR_FILENO);
    for (unsigned int i = 1; i < ARGS_REQUIRED; i++) {
        if (arg_check_positive_int(argv[i]) != EPI_SUCCESS)
            return EPI_FAILURE;
    }
    return fill_infos(pano, argv + 1, argc - 1);
}
