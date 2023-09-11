#include "dfs.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Graph *g = graph_construct(10);

    graph_add_undirected_edge(g, 0, 1);
    graph_add_undirected_edge(g, 0, 2);
    graph_add_undirected_edge(g, 0, 3);
    graph_add_undirected_edge(g, 1, 4);
    graph_add_undirected_edge(g, 1, 5);
    graph_add_undirected_edge(g, 2, 6);
    graph_add_undirected_edge(g, 2, 7);

    int *path = dfs_path(g);

    for (int i = 0; i < graph_num_vertices(g); i++) {
        printf("%d ", path[i]);
    }

    graph_destroy(g);

    free(path);
}
