#include "stack.h"

void empty (TStack *stack) {
    stack->top = (TStack *)malloc(sizeof(TStack));
    stack->bottom = stack->top;
    stack->top->next = NULL;
    stack->size = 0;
}

int is_empty(TStack stack) {
    return (stack.top == stack.bottom);
}

int size(TStack stack) {
    return stack.size;
}

void push(TStack *stack, int x) {
    TCell *aux;
    aux = (TCell *)malloc(sizeof(TCell));
    stack->top->item = x;
    aux->next = stack->top;
    stack->top = aux;
    stack->size++;
}

void pop(TStack *stack, int *item) {
    TCell *q;
    if (is_empty(*stack)) {
        item = 0;
        return;
    }
    q = stack->top;
    stack->top = q->next;
    *item = q->next->item;
    free(q);
    stack->size--;
}

void free_stack(TStack *stack) {
    int x;
    while (!is_empty(*stack)) {
        pop(stack, &x);
    }
    free(stack->top);
}

void print_stack(TStack *stack);