#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main() {
    TGraph *g1 = create_graph(5);

    free_graph(g1);
    return 0;
}
