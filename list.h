#ifndef TADGRAFO_LIST_H
#define TADGRAFO_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct cell
{
    int item;
    struct cell *next;
} TCell;

typedef struct
{
    TCell* first;
    TCell* last;
    int size;
} TList;

void FLVazia(TList *List);

int Vazia(TList List);

int Tamanho (TList List);

void Inserir (int x, TList *List);

void LerProduto(int *x);

void Imprimir(TList list);

int Pesquisar2 (TList List, int Item);

TCell* Pesquisar (TList List, int Item);

void Excluir (TList *List, int *Item);

void Liberar (TList *List);

#endif //TADGRAFO_LIST_H
