#include "dijkstra.h"
#include "priority_queue/heap.h"
#include "graph/graph.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Graph *g = graph_construct(5);
    
    graph_add_directed_edge(g, 0, 1, 1.0);
    graph_add_directed_edge(g, 0, 2, 2.0);
    graph_add_directed_edge(g, 1, 3, 3.0);
    graph_add_directed_edge(g, 2, 3, 4.0);
    graph_add_directed_edge(g, 3, 4, 5.0);

    graph_print(g);

    int *path = dijkstra_algorithm(g, 0, 4);

    for(int i = 0; i < 5; i++)
        printf("%d ", path[i]);
    
    free(path);
    graph_destroy(g);

    return 0;
}
