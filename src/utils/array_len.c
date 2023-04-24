/*
** EPITECH PROJECT, 2023
** utils
** File description:
** array_len
*/

int array_len(const void *const arr)
{
    void **get_len = (void **)arr;
    int ind = 0;

    if (!arr)
        return -1;
    while (get_len[ind])
        ind++;
    return ind;
}
