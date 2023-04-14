#include "graph.h"

int main() {
    TGraph *g1 = create_graph(3);
    TList l1;
    ml_empty(&l1);

    insert(1, &l1);
    insert(2, &l1);
    delete_by_index(&l1, 0);
    print_list(l1);

    add_undirected_edge(g1, 0, 1);

    // printGraph(g1);

    free_graph(g1);
    free_list(&l1);
    return 0;
}
