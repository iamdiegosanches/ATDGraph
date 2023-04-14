#include "list.h"

void ml_empty(TList *list) {
    list->first = (TCell *)malloc(sizeof(TCell));
    list->last = list->first;
    list->first->next = NULL;
    list->size = 0;
}

int is_empty(TList list) {
    return (list.first == list.last);
}

int size(TList list) {
    return list.size;
}

void insert(int x, TList *list) {
    list->last->next = (TCell *) malloc(sizeof(TCell));
    list->last = list->last->next;
    list->last->item = x;
    list->last->next = NULL;
    list->size++;
}

void print_list(TList list) {
    TCell *aux;
    aux = list.first->next;
    while (aux != NULL) {
        printf("%d\n", aux->item);
        aux = aux->next;
    }
}

TCell *search(TList list, int item) {
    TCell *aux;
    aux = list.first;
    while (aux->next != NULL) {
        if (aux->next->item == item)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void delete(TList *list, int *item) {
    TCell *aux1, *aux2;
    aux1 = search(*list, *item);
    if (aux1 != NULL) {
        aux2 = aux1->next;
        aux1->next = aux2->next;
        *item = aux2->item;
        if (aux1->next == NULL)
            list->last = aux1;
        free(aux2);
        list->size--;
    } else
        *item = -1;
}

void free_list(TList *list) {
    while (!is_empty(*list)) {
        delete(list, &list->first->next->item);
    }
    free(list->first);
}