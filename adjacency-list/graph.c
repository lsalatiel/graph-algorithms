#include "graph.h"
#include "forward_list.h"
#include <stdlib.h>
#include <stdio.h>

struct Graph {
    int num_vertices;
    ForwardList **adjacency_list;
};

Graph *graph_construct(int num_vertices) {
    Graph *g = malloc(sizeof(Graph));

    g->num_vertices = num_vertices;

    g->adjacency_list = malloc(num_vertices * sizeof(ForwardList *));

    for(int i = 0; i < num_vertices; i++) {
        g->adjacency_list[i] = forward_list_construct();
    }

    return g;
}

void graph_destroy(Graph *g) {
    for(int i = 0; i < g->num_vertices; i++) {
        forward_list_destroy(g->adjacency_list[i]);
    }

    free(g->adjacency_list);
    free(g);
}

void graph_add_undirected_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    forward_list_push_front(g->adjacency_list[p], q);
    forward_list_push_front(g->adjacency_list[q], p);
}

void graph_add_directed_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    forward_list_push_front(g->adjacency_list[p], q);
}

void graph_remove_undirected_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    forward_list_remove(g->adjacency_list[p], q);
    forward_list_remove(g->adjacency_list[q], p);
}

void remove_directed_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    forward_list_remove(g->adjacency_list[p], q);
}

int graph_num_vertices(Graph *g) {
    return g->num_vertices;
}

void graph_print(Graph *g) {
    for(int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        forward_list_print(g->adjacency_list[i]);
        printf("\n");
    }
}
