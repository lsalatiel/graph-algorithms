#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *node_construct(int value, Node *next) {
    Node *n = malloc(sizeof(Node));
    
    n->value = value;
    n->next = next;

    return n;
}

void node_destroy(Node *n) {
    free(n);
}
