#include "graph.h"

TGraph *create_graph(int num_vertices) {
    TGraph *graph = (TGraph *) malloc(sizeof(TGraph));
    graph->count_nodes = num_vertices;

    graph->adj_list = (Node **) malloc(num_vertices * sizeof(Node *));

    for (int i = 0; i < num_vertices; ++i) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void free_graph(TGraph *graph) {
    for (int i = 0; i < graph->count_nodes; ++i) {
        Node *node = graph->adj_list[i];
        while (node != NULL) {
            Node *temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(graph->adj_list);
    free(graph);
}