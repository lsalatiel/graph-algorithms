#include "graph.h"
#include <stdio.h>

int main() {
    Graph *g = graph_construct(5);

#ifdef WEIGHTED
    graph_add_undirected_edge(g, 0, 4, 1);
    graph_add_undirected_edge(g, 4, 1, 4);
    graph_add_undirected_edge(g, 3, 2, 2);
    graph_add_undirected_edge(g, 1, 2, 9);
    graph_add_undirected_edge(g, 1, 5, 0);

    graph_remove_undirected_edge(g, 0, 4);
    graph_remove_undirected_edge(g, 1, 2);
#else
    graph_add_undirected_edge(g, 0, 4);
    graph_add_undirected_edge(g, 4, 1);
    graph_add_undirected_edge(g, 3, 2);
    graph_add_undirected_edge(g, 1, 2);
    graph_add_undirected_edge(g, 1, 5);

    graph_remove_undirected_edge(g, 0, 4);
    graph_remove_undirected_edge(g, 1, 2);
#endif

    graph_print(g);

    graph_destroy(g);

    return 0;
}
