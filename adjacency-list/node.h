#ifndef NODE_H_
#define NODE_H_

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *node_construct(int value, Node *next);

void node_destroy(Node *n);

#endif
