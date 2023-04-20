/*
** EPITECH PROJECT, 2023
** src
** File description:
** parse_args
*/

#include <panoramix/panoramix.h>
#include <unistd.h>

int parse_args(panoramix_t *pano, int argc, char *const argv[])
{
    if (!argv || argc != ARGS_REQUIRED || !pano)
        return print_usage(STDERR_FILENO);
    return EPI_SUCCESS;
}
