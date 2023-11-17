#include "dllist.h"

DLList *dllCreate()
{
    DLList *l = (DLList *)malloc(sizeof(DLList));
    if (l != NULL)
    {
        l->first = NULL;
    }
    return l;
}

void dllDestroy(DLList *l)
{
    if (l != NULL)
    {
        DLNode *current = l->first;
        DLNode *next;

        while (current != NULL)
        {
            next = current->next;
            free(current->data);
            free(current);
            current = next;
        }

        free(l);
    }
}

int dllInsertFirst(DLList *l, Time *data)
{
    if (l == NULL || data == NULL)
    {
        return 0;
    }

    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = data;
    newNode->next = l->first;
    newNode->prev = NULL;

    if (l->first != NULL)
    {
        l->first->prev = newNode;
    }

    l->first = newNode;

    return 1;
}

int dllInsertLast(DLList *l, Time *data)
{
    if (l == NULL || data == NULL)
    {
        return 0;
    }

    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (l->first == NULL)
    {
        l->first = newNode;
        newNode->prev = NULL;
    }
    else
    {
        DLNode *current = l->first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return 1;
}

Time *dllRemoveSpec(DLList *l, Time *key, int (*cmp)(Time *, Time *))
{
    if (l == NULL || key == NULL)
    {
        return NULL;
    }

    DLNode *current = l->first;
    while (current != NULL)
    {
        if (cmp(current->data, key))
        {
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            if (l->first == current)
            {
                l->first = current->next;
            }

            Time *data = current->data;
            free(current);
            return data;
        }
        current = current->next;
    }

    return NULL;
}

Time *dllFind(DLList *l, Time *key, int (*compare)(Time *, Time *))
{
    DLNode *current = l->first;
    while (current != NULL)
    {
        if (compare(current->data, key))
        {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}