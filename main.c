#include "graph.h"

int main() {
    TGraph *g1 = create_graph(3);

    printGraph(g1);

    free_graph(g1);
    return 0;
}
