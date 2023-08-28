#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "forward_list.h"

typedef struct Graph Graph;

Graph *graph_construct(int num_vertices);

void graph_destroy(Graph *g);

void graph_add_edge(Graph *g, int p, int q);

int graph_num_vertices(Graph *g);

void graph_print(Graph *g);

#endif
