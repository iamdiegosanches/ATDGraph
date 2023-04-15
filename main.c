#include "graph.h"

int main() {
    TGraph *g1 = create_graph(3);

    add_directed_edge(g1, 0, 1);
    add_directed_edge(g1, 1, 2);

    TList path = bfs(g1, 0);

    print_list(path);
    printf("\n");
    printGraph(g1);

    free_graph(g1);
    free_list(&path);
    return 0;
}
