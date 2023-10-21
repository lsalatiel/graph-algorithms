#include "dijkstra.h"
#include "priority_queue/heap.h"
#include "graph/graph.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Graph *g = graph_construct(5);

    graph_add_directed_edge(g, 0, 1, 10);
    graph_add_directed_edge(g, 0, 2, 3);
    graph_add_directed_edge(g, 2, 1, 4);
    graph_add_directed_edge(g, 1, 2, 1);
    graph_add_directed_edge(g, 1, 3, 2);
    graph_add_directed_edge(g, 2, 3, 8);
    graph_add_directed_edge(g, 2, 4, 2);
    graph_add_directed_edge(g, 3, 4, 7);
    graph_add_directed_edge(g, 4, 3, 9);

    graph_print(g);

    int *path = dijkstra_algorithm(g, 0, 1);

    for(int i = 0; i < 5; i++) {
        if(path[i] == -1) {
            printf("NULL\n");
            break;
        }
        printf("%d -> ", path[i]);
    }
    
    free(path);
    graph_destroy(g);

    return 0;
}
