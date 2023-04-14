#include "graph.h"

int main() {
    TGraph *g1 = create_graph(3);

    TList l1;
    int x;

    ml_empty(&l1);

    insert(1, &l1);
    insert(2, &l1);
    x = delete_by_index(&l1, 0);
    printf("%d\n", x);
    // print_list(l1);

    add_directed_edge(g1, 0, 1);
    add_directed_edge(g1, 1, 2);

    //int *path = bfs(g1, 0);

    printGraph(g1);

    free_graph(g1);
    //free(path);
    free_list(&l1);
    return 0;
}
