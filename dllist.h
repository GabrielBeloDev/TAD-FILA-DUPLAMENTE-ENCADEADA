#ifndef DLLIST_H
#define DLLIST_H

#include <stdlib.h>

typedef struct
{
    char nome[30];
    int vitorias;
    float pontuacao;
} Time;

typedef struct _dlnode_
{
    struct _dlnode_ *next, *prev;
    Time *data;
} DLNode;

typedef struct _dllist_
{
    DLNode *first;
    DLNode *cur;
} DLList;

DLList *dllCreate();
void dllDestroy(DLList *l);
int dllInsertFirst(DLList *l, Time *data);
int dllInsertLast(DLList *l, Time *data);
Time *dllRemoveSpec(DLList *l, Time *key, int (*cmp)(Time *, Time *));
int comparaTime(Time *a, Time *b);
void mostrarTime(Time *t);

#endif
