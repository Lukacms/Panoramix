/*
** EPITECH PROJECT, 2023
** tests
** File description:
** tests_parse_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <panoramix/functions.h>
#include <panoramix/panoramix.h>

void redirect(void);

Test(parse_args, test_null_struct, .init = redirect)
{
    char *const argv[] = {0};

    cr_assert_eq(parse_args(NULL, ARGS_REQUIRED, argv), EPI_FAILURE);
    cr_assert_stderr_eq_str(USAGE);
}

Test(parse_args, test_wrong_arg_nb, .init = redirect)
{
    panoramix_t pano = {0};

    cr_assert_eq(parse_args(&pano, 87, NULL), EPI_FAILURE);
    cr_assert_stderr_eq_str(USAGE);
}

Test(parse_args, test_null_argv, .init = redirect)
{
    panoramix_t pano = {0};

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, NULL), EPI_FAILURE);
    cr_assert_stderr_eq_str(USAGE);
}

Test(parse_args, invalid_arg_nan_1, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"toto", "nan", "5", "6", "7"};
    char *error = "Panoramix: nan value must be a number.\n";

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_FAILURE);
    cr_assert_stderr_eq_str(error);
}

Test(parse_args, invalid_arg_nan_2, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"toto", "5", "@nan", "6", "7"};
    char *error = "Panoramix: @nan value must be a number.\n";

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_FAILURE);
    cr_assert_stderr_eq_str(error);
}

Test(parse_args, invalid_arg_negative_num, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"toto", "-6", "5", "6", "7"};
    char *error = "Panoramix: -6 value must be > 0.\n";

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_FAILURE);
    cr_assert_stderr_eq_str(error);
}

Test(parse_args, valid_parse_args)
{
    panoramix_t pano = {0};
    char *const argv[] = {"toto", "6", "5", "6", "7"};

    cr_assert_eq(parse_args(&pano, ARGS_REQUIRED, argv), EPI_SUCCESS);
    cr_assert_eq(pano.nb_villagers, 6);
}

Test(fill_infos, tests_null_pano, .init = redirect)
{
    panoramix_t pano = {0};
    char *const argv[] = {"toto", "6", "5", "6", "7"};

    cr_assert_eq(fill_infos(NULL, NULL, 0), EPI_FAILURE);
    cr_assert_eq(fill_infos(&pano, NULL, 0), EPI_FAILURE);
    cr_assert_eq(fill_infos(&pano, argv, 0), EPI_FAILURE);
}
