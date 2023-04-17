#include "graph.h"

int main() {
    TGraph *g1 = create_graph(9);

    add_directed_edge(g1, 0, 3);
    add_directed_edge(g1, 0, 5);
    add_directed_edge(g1, 0, 6);
    add_directed_edge(g1, 5, 7);
    add_directed_edge(g1, 3, 6);
    add_directed_edge(g1, 7, 0);
    add_directed_edge(g1, 6, 8);
    add_directed_edge(g1, 7, 1);
    add_directed_edge(g1, 1, 4);
    add_directed_edge(g1, 2, 4);
    add_directed_edge(g1, 2, 1);

    TList path = bfs(g1, 0);

    //print_list(path);
    //printf("\n");
    //printGraph(g1);
    //delete_by_index(&path, 1);
    print_list(path);

    free_graph(g1);
    free_list(&path);
    return 0;
}
