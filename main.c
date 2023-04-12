#include "graph.h"

int main() {
    TGraph *g1 = create_graph(3);

    add_undirected_edge(g1, 0, 1);

    printGraph(g1);

    free_graph(g1);
    return 0;
}
