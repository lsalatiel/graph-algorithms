#include "graph.h"
#include <stdio.h>

int main() {
    Graph *g = graph_construct(5);

    graph_add_edge(g, 0, 4);
    graph_add_edge(g, 4, 1);
    graph_add_edge(g, 3, 2);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 5);

    graph_print(g);

    graph_destroy(g);

    return 0;
}
