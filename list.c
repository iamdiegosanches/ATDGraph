#include "list.h"

void ml_empty(TList *list);

int is_empty(TList list);

int size(TList list);

void insert(int x, TList *list);

void print_list(TList list);

int search2(TList list, int item);

TCell *search(TList list, int item);

void delete(TList *list, int *item);

void free_list(TList *list);