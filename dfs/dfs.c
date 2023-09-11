#include "dfs.h"
#include "graph.h"
#include "linked_list.h"
#include <stdlib.h>

void __dfs(Graph *g, int *path, int *visited, int vertex, int *find_count) {
    visited[vertex] = 1;

    path[(*find_count)++] = vertex;
    
    LinkedList **adjacency_list = graph_adjacency_list(g);

    ListIterator *it = list_iterator_construct(adjacency_list[vertex]);
    while (!list_iterator_is_over(it)) {
        int next = list_iterator_next(it);

        if (!visited[next]) {
            __dfs(g, path, visited, next, find_count);
        }
    }

    list_iterator_free(it);
}

int *dfs_path(Graph *g) {
    int *path = malloc(sizeof(int) * graph_num_vertices(g));

    int *visited = malloc(sizeof(int) * graph_num_vertices(g));

    for (int i = 0; i < graph_num_vertices(g); i++) {
        visited[i] = 0;
    }

    
    int *find_count = malloc(sizeof(int));
    *find_count = 0;
    for (int i = 0; i < graph_num_vertices(g); i++) {
        if (!visited[i]) {
            __dfs(g, path, visited, i, find_count);
        }
    }

    free(find_count);
    free(visited);

    return path;
}
