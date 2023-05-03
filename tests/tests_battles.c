/*
** EPITECH PROJECT, 2023
** tests
** File description:
** tests_battles
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <panoramix/functions.h>
#include <panoramix/panoramix.h>

void redirect(void);

Test(launch_battle, null_arg)
{
    cr_assert_eq(launch_battle(NULL), EPI_FAILURE);
}

Test(launch_battle, perfect_case, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"./panoramix", "3", "5", "3", "1"};

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_SUCCESS);
    cr_assert_eq(launch_battle(&pano), EPI_SUCCESS);
}

Test(launch_battle, imperfect_case_1, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"./panoramix", "9", "5", "3", "1"};

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_SUCCESS);
    cr_assert_eq(launch_battle(&pano), EPI_SUCCESS);
}

Test(launch_battle, imperfect_case_2, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"./panoramix", "2", "3", "3", "2"};

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_SUCCESS);
    cr_assert_eq(launch_battle(&pano), EPI_SUCCESS);
}

Test(launch_battle, imperfect_case_3, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"./panoramix", "3", "5", "3", "3"};

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_SUCCESS);
    cr_assert_eq(launch_battle(&pano), EPI_SUCCESS);
}
