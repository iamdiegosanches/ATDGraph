#ifndef TADGRAFO_STACK_H
#define TADGRAFO_STACK_H

#include <stdlib.h>
#include <stdio.h>


typedef struct cell {
    int item;
    struct cell* next;
} TCell;

typedef struct {
    TCell *bottom;
    TCell *top;
    int size;
} TStack;

void empty (TStack *stack);

int is_empty(TStack stack);

int size(TStack stack);

void push(TStack *stack, int x);

void pop(TStack *stack, int *item);

void free_stack(TStack *stack);

void print_stack(TStack *stack);

#endif //TADGRAFO_STACK_H
