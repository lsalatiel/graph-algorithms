#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

struct Graph {
    int num_vertices;
    bool **adjacency_matrix;
};

Graph *graph_construct(int num_vertices) {
    Graph *g = malloc(sizeof(Graph));

    g->num_vertices = num_vertices;

    g->adjacency_matrix = malloc(num_vertices * sizeof(bool *));

    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_matrix[i] = calloc(num_vertices, sizeof(bool));
    }

    return g;
}

void graph_destroy(Graph *g) {
    for(int i = 0; i < g->num_vertices; i++) {
        free(g->adjacency_matrix[i]);
    }
    
    free(g->adjacency_matrix);
    free(g);
}

void graph_add_undirected_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    g->adjacency_matrix[p][q] = true;
    g->adjacency_matrix[q][p] = true;
}

void graph_add_directed_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    g->adjacency_matrix[p][q] = true;
}

void graph_remove_undirected_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    g->adjacency_matrix[p][q] = false;
    g->adjacency_matrix[q][p] = false;
}

void remove_directed_edge(Graph *g, int p, int q) {
    if(p < 0 || p >= g->num_vertices || q < 0 || q >= g->num_vertices)
        return;

    g->adjacency_matrix[p][q] = false;
}

int graph_num_vertices(Graph *g) {
    return g->num_vertices;
}

void graph_print(Graph *g) {
    for(int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        for(int j = 0; j < g->num_vertices; j++) {
            if(g->adjacency_matrix[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }
}
