#ifndef TADGRAFO_LIST_H
#define TADGRAFO_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct cell {
    int item;
    struct cell *next;
} TCell;

typedef struct {
    TCell *first;
    TCell *last;
    int size;
} TList;

void ml_empty(TList *list);

int is_empty(TList list);

int size(TList list);

void insert(int x, TList *list);

void print_list(TList list);

TCell *search(TList list, int item);

void delete(TList *list, int *item);

int delete_by_index(TList *list, int index);

void free_list(TList *list);

#endif //TADGRAFO_LIST_H
