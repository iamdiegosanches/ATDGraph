#ifndef TADGRAFO_GRAFO_H
#define TADGRAFO_GRAFO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int data;
    struct Node* next;
} Node;

typedef struct
{
    int count_nodes;
    Node** adj_list;
} TGraph;

TGraph* create_graph(int num_vertices);
void add_directed_edge(TGraph * graph, int data);
void add_undirected_edge(TGraph * graph, int data);
void free_graph(TGraph *graph);

#endif //TADGRAFO_GRAFO_H
