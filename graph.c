#include "graph.h"

TGraph *create_graph(int num_vertices) {
    assert(num_vertices >= 0);
    TGraph *graph = (TGraph *) malloc(sizeof(TGraph));
    assert(graph != NULL);
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
    assert(graph != NULL);
    graph->adj_list[u][v].data = v;
    graph->count_edges++;
}

void add_undirected_edge(TGraph *graph, int u, int v) {
    assert(graph != NULL);
    add_directed_edge(graph, u, v);
    add_directed_edge(graph, v, u);
}

TList bfs(TGraph *graph, int s) {
    assert(graph != NULL);
    int u;
    TList Q;
    TList R;
    ml_empty(&Q);
    ml_empty(&R);
    int *desc = malloc(graph->count_nodes * sizeof(int));
    for (int i = 0; i < graph->count_nodes; ++i) {
        *(desc + i) = 0;
    }
    insert(s, &Q);
    insert(s, &R);
    *(desc + s) = 1;

    while (!is_empty(Q)) {
        u = delete_by_index(&Q, 1);
        for (int v = 0; v < graph->count_nodes; ++v) {
            if (graph->adj_list[u][v].data != -1) {
                if (*(desc + v) == 0) {
                    insert(v, &Q);
                    insert(v, &R);
                    *(desc + v) = 1;
                }
            }
        }
    }
    free_list(&Q);
    return R;
}

TList dfs(TGraph *graph, int s) {
    assert(graph != NULL);
    int u, pop;
    TList S;
    TList R;
    ml_empty(&S);
    ml_empty(&R);
    int *desc = malloc(graph->count_nodes * sizeof(int));
    for (int i = 0; i < graph->count_nodes; ++i) {
        *(desc + i) = 0;
    }
    insert(s, &S);
    insert(s, &R);
    *(desc + s) = 1;
    while (!is_empty(S)) {
        u = S.last->item;
        pop = 1;
        for (int v = 0; v < graph->count_nodes; ++v) {
            if (graph->adj_list[u][v].data != -1) {
                if (*(desc + v) == 0) {
                    pop = 0;
                    insert(v, &S);
                    insert(v, &R);
                    *(desc + v) = 1;
                    break;
                }
            }
        }
        if (pop == 1) {
            delete_by_index(&S, size(S));
        }
    }
    return R;
}

void printGraph(TGraph *graph) {
    assert(graph != NULL);
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
    assert(graph != NULL);
    for (int i = 0; i < graph->count_nodes; ++i) {
        free(graph->adj_list[i]);
    }
    free(graph->adj_list);
    free(graph);
}