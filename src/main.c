/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <panoramix/functions.h>
#include <panoramix/panoramix.h>

int main(int argc, char *const argv[])
{
    panoramix_t pano = {0};

    if (parse_args(&pano, argc, argv) != EPI_SUCCESS)
        return EPI_FAILURE;
    return launch_battle(&pano);
}
