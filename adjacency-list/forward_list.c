#include <stdio.h>
#include <stdlib.h>
#include "forward_list.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *node_construct(int value, Node *next) {
    Node *n = malloc(sizeof(Node));
    
    n->value = value;
    n->next = next;

    return n;
}

void node_destroy(Node *n) {
    free(n);
}

struct ForwardList {
    int size;
    Node *head;
};

ForwardList* forward_list_construct() {
    ForwardList *l = malloc(sizeof(ForwardList));
    l->size = 0;
    l->head = NULL;

    return l;
}

void node_destroy_recursive(Node *n) {
    if(n == NULL) return;

    node_destroy_recursive(n->next);
    free(n);
}

void forward_list_destroy(ForwardList* l) {
    node_destroy_recursive(l->head);
    free(l);
}

int forward_list_size(ForwardList* l) {
    return l->size;
}

void forward_list_push_front(ForwardList* l, int val) {
    Node *n = node_construct(val, l->head);
    l->head = n;

    l->size++;
}

void forward_list_print(ForwardList* l) {
    Node *n = l->head;
    
    printf("[");
    int i = 0;
    while(n != NULL) {
        printf("%d", n->value);
        if(i != l->size - 1)
            printf(", ");
        
        n = n->next;

        i++;
    }
    
    printf("]\n");

    l->size++;
}

void forward_list_remove(ForwardList* l, int val) {
    if(l->head == NULL) return;

    Node *prev = NULL;
    Node *curr = l->head;
    
    while(curr) {
        int remove = 0;
        if(curr->value == val) {
            if(!prev)
                l->head = curr->next;
            else
                prev->next = curr->next;
            remove = 1;
            l->size--;
        }
        else
            prev = curr;
        
        Node *to_remove = curr;
        curr = curr->next;

        if(remove)
            free(to_remove);
    }
}

