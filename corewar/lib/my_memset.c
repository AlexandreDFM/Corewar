/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** my_memset
*/

void *my_memset(void *dest, int value, int length)
{
    char *ptr = dest;
    while (length-- > 0) {
        *ptr++ = value;
    }
    return dest;
}
