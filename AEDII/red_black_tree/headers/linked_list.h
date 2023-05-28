#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>

typedef struct ListNode
{
    TreeNode *tree_node;
    struct ListNode *next;
} ListNode;

ListNode* insert_start_ll(ListNode *head, TreeNode *tree_node)
{
    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->tree_node = tree_node;
    new_node->next = head;

    head = new_node;

    return head;
}

ListNode* insert_last_ll(ListNode *head, TreeNode *tree_node)
{
    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    ListNode *last_node = head;

    new_node->tree_node = tree_node;
    new_node->next = NULL;

    if (head == NULL)
        head = new_node;
    else
    {
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
    }
    return head;
}

ListNode* delete_first_from_ll(ListNode *head)
{
    if (head != NULL)
    {
        ListNode *new_head = (ListNode *) malloc(sizeof(ListNode));

        new_head = head->next;

        free(head);

        return new_head;
    }

    return NULL;
}

ListNode* delete_last_from_ll(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    ListNode *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    free(second_last->next);

    return head;
}
#endif