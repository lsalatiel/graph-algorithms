#ifndef FORWARD_LIST_H_
#define FORWARD_LIST_H_

#include "node.h"

typedef struct {
    int size;
    Node *head;
} ForwardList;

// cria uma lista
ForwardList* forward_list_construct();

// retorna o número de elementos na lista
int forward_list_size(ForwardList* l);

// adiciona um item no início da lista
void forward_list_push_front(ForwardList* l, int val);

// mostra a lista na tela
void forward_list_print(ForwardList* l);

// retorna o i-ésimo elemento da lista
int forward_list_get(ForwardList* l, int i);

// remove o primeiro elemento
int forward_list_pop_front(ForwardList* l);

// retorna uma lista contendo o reverso de outra
ForwardList* forward_list_reverse(ForwardList* l);

// libera o espaço alocado para a lista
void forward_list_destroy(ForwardList* l);

// remove todas as ocorrências de um valor da lista
void forward_list_remove(ForwardList* l, int val);

// adiciona os itens da lista m no início da lista l
void forward_list_cat(ForwardList* l, ForwardList* m);

#endif
