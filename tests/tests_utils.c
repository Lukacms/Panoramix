/*
** EPITECH PROJECT, 2023
** tests
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <panoramix/functions.h>
#include <panoramix/panoramix.h>

void redirect(void);

Test(array_len, test_null_len)
{
    cr_assert_eq(array_len(NULL), -1);
}

Test(array_len, test_basic_len)
{
    char *to_get_len[] = {"un", "deux", "trois", NULL};

    cr_assert_eq(array_len(to_get_len), 3);
}

Test(villagers_fighting, test_null_gauls)
{
    cr_assert_eq(villagers_fighting(NULL), false);
}

Test(villagers_fighting, test_villagers_not_fighting)
{
    villager_t gauls[] = {{.fighting = false, .id = 5, .fights_left = 0},
                          {.id = -1}};

    cr_assert_eq(villagers_fighting(gauls), false);
}

Test(villagers_fighting, test_villagers_fighting)
{
    villager_t gauls[] = {{.fighting = false, .id = 5, .fights_left = 5},
                          {.id = -1}};

    cr_assert_eq(villagers_fighting(gauls), true);
}

Test(print_usage, usage_error, .init = redirect)
{
    cr_assert_eq(print_usage(STDERR_FILENO), EPI_FAILURE);
    cr_assert_stderr_eq_str(USAGE);
}

Test(print_usage, usage_out, .init = redirect)
{
    cr_assert_eq(print_usage(STDOUT_FILENO), EPI_SUCCESS);
    cr_assert_stdout_eq_str(USAGE);
}
