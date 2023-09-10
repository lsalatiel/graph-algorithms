#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "linked_list.h"

typedef struct Graph Graph;

/**
 * Create a new graph with num_vertices vertices and no edges.
 *
 * @param num_vertices the number of vertices in the graph
 *
 * @return a pointer to the new graph
 */
Graph *graph_construct(int num_vertices);

/**
 * Destroy a graph, freeing all associated memory.
 *
 * @param g the graph to be destroyed
 */
void graph_destroy(Graph *g);

/**
 * Add an edge to a graph.
 *
 * @param g the graph to add the edge to
 * @param p,q the edge (p,q) to be added
 */
void graph_add_undirected_edge(Graph *g, int p, int q);

/**
 * Add a directed edge to a graph.
 *
 * @param g the graph to add the edge to
 * @param p,q the edge (p,q) to be added - from p to q
 */
void graph_add_directed_edge(Graph *g, int p, int q);

/**
 * Remove an edge from a graph.
 *
 * @param g the graph to remove the edge from
 * @param p,q the edge (p,q) to be removed
 */
void graph_remove_undirected_edge(Graph *g, int p, int q);

/**
 * Remove a directed edge from a graph.
 *
 * @param g the graph to remove the edge from
 * @param p,q the edge (p,q) to be removed - from p to q
 */
void remove_directed_edge(Graph *g, int p, int q);

/**
 * Return the number of vertices in a graph.
 *
 * @param g the graph to remove the edge from
 */
int graph_num_vertices(Graph *g);

/**
 * Print a graph.
 *
 * @param g the graph to be printed
 */
void graph_print(Graph *g);

#endif
