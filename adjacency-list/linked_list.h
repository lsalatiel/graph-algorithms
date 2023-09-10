#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct LinkedList LinkedList;

// cria uma lista
LinkedList* linked_list_construct();

// retorna o número de elementos na lista
int linked_list_size(LinkedList* l);

// adiciona um item no início da lista
void linked_list_push_front(LinkedList* l, int val);

// mostra a lista na tela
void linked_list_print(LinkedList* l);

// libera o espaço alocado para a lista
void linked_list_destroy(LinkedList* l);

// remove todas as ocorrências de um valor da lista
void linked_list_remove(LinkedList* l, int val);

#endif
