#include "graph.h"

TGraph *create_graph(int num_vertices) {
    TGraph *graph = (TGraph *) malloc(sizeof(TGraph));
    graph->count_nodes = num_vertices;
    graph->count_edges = 0;
    graph->adj_list = (Node **) malloc(num_vertices * sizeof(Node *));

    for (int i = 0; i < num_vertices; ++i) {
        graph->adj_list[i] = (Node *) malloc(num_vertices * sizeof (Node));
        for (int j = 0; j < num_vertices; ++j) {
            graph->adj_list[i][j].data = -1;
        }
    }
    return graph;
}

void add_directed_edge(TGraph *graph, int u, int v) {
    graph->adj_list[u][v].data = v;
    graph->count_edges++;
}

void printGraph(TGraph *graph) {
    for (int i = 0; i < graph->count_nodes; ++i) {
        printf(("%d:\n"), i);
        for (int j = 0; j < graph->count_nodes; ++j) {
            if (graph->adj_list[i][j].data != -1)
                printf(" (%d) ", graph->adj_list[i][j].data);
        }
        printf("\n");
    }
}

void free_graph(TGraph *graph) {
    for (int i = 0; i < graph->count_nodes; ++i) {
        free(graph->adj_list[i]);
    }
    free(graph->adj_list);
    free(graph);
}