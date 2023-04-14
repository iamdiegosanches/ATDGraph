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

void add_undirected_edge(TGraph *graph, int u, int v) {
    add_directed_edge(graph, u, v);
    add_directed_edge(graph, v, u);
}

int *bfs(TGraph *graph, int s) {
    int u;
    TList Q;
    TList R;
    ml_empty(&Q);
    ml_empty(&R);
    int *desc = malloc(graph->count_nodes * sizeof(int));
    for (int i = 0; i < graph->count_nodes; ++i) {
        desc[i] = 0;
    }
    insert(s, &Q);
    insert(s, &R);
    desc[s] = 1;

    while (!is_empty(Q)) {
        u = delete_by_index(&Q, 0);
        for (int v = 0; v < graph->count_nodes; ++v) {
            if (graph->adj_list[u][v].data != -1) {
                if (desc[v] == 0) {
                    insert(v, &Q);
                    insert(v, &R);
                    desc[v] = 1;
                }
            }
        }
    }
    free_list(&Q);
    free_list(&R);
    return desc;
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