#ifndef TADGRAFO_GRAPH_H
#define TADGRAFO_GRAPH_H

#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int data;
} Node;

typedef struct {
    int count_nodes;
    Node **adj_list;
} TGraph;

TGraph *create_graph(int num_vertices);

void add_directed_edge(TGraph *graph, int u, int v);

void add_undirected_edge(TGraph *graph, int u, int v);

void printGraph(TGraph *graph);

void free_graph(TGraph *graph);

#endif //TADGRAFO_GRAPH_H
