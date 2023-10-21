#include <stdio.h>
#include "dijkstra.h"
#include "graph/graph.h"
#include "graph/linked_list.h"
#include "priority_queue/heap.h"
#include <stdlib.h>
#include <math.h>

void __dijkstra_relax(Heap *h, double *dist, double u_w, int v, double w) {
    double new_priority = u_w + w;
    if(heap_get_priority(h, v) > new_priority) {
        heap_decrease_key(h, v, new_priority);
        dist[v] = new_priority;
    }
}

int *dijkstra_algorithm(Graph *g, int s, int t) {
    int *path = malloc(sizeof(int) * graph_num_vertices(g));
    for(int i = 0; i < graph_num_vertices(g); i++) path[i] = -1;
    int path_size = 0;

    Heap *h = heap_init(graph_num_vertices(g));
    double *dist = malloc(sizeof(double) * graph_num_vertices(g));

    for(int i = 0; i < graph_num_vertices(g); i++) {
        heap_insert(h, i, i == s ? 0.0 : INFINITY);
        dist[i] = i == s ? 0 : INFINITY;
    }

    LinkedList **l = graph_adjacency_list(g);

    while(!heap_empty(h)) {
        int u = heap_min(h);
        double u_priority = heap_get_priority(h, u);
        heap_pop(h);
        path[path_size++] = u;
        
        if(u == t) break;

        ListIterator *it = list_iterator_construct(l[u]);
        if(it == NULL) continue;
        while(!list_iterator_is_over(it)) {
            int v = list_iterator_next(it);
            double w = graph_get_weight(g, u, v);
            __dijkstra_relax(h, dist, u_priority, v, w);
        }

        list_iterator_free(it);
    }

    heap_destroy(h);

    printf("Cost: %lf\n", dist[t]);

    return path;
}
