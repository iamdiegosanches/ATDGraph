#include "graph.h"

int main() {
    TGraph *g1 = create_graph(3);

    add_directed_edge(g1, 0, 1);
    add_directed_edge(g1, 1, 2);

    printGraph(g1);

    free_graph(g1);
    return 0;
}
