/*
** EPITECH PROJECT, 2022
** COMMANDS_UTILS
** File description:
** Utilities functions for t_commands struct
*/

#include "../include/asm.h"

void push_back_commands(t_commands *head, t_commands *node)
{
    t_commands *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

void push_back_counter(t_counter *head, t_counter *node)
{
    t_counter *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

void swapnodes(t_counter **head, int x, int y)
{
    if (x == y) return;
    // Search for x (keep track of prevX and CurrX
    t_counter *prevX = NULL, *currX = *head;
    while (currX && currX->sizeline != x) {
        prevX = currX;
        currX = currX->next;
    }
    // Search for y (keep track of prevY and CurrY
    t_counter *prevY = NULL, *currY = *head;
    while (currY && currY->sizeline != y) {
        prevY = currY;
        currY = currY->next;
    }
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL) return;
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head = currY;
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head = currX;
    // Swap next pointers
    t_counter *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
