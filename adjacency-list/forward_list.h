#ifndef FORWARD_LIST_H_
#define FORWARD_LIST_H_

typedef struct ForwardList ForwardList;

// cria uma lista
ForwardList* forward_list_construct();

// retorna o número de elementos na lista
int forward_list_size(ForwardList* l);

// adiciona um item no início da lista
void forward_list_push_front(ForwardList* l, int val);

// mostra a lista na tela
void forward_list_print(ForwardList* l);

// libera o espaço alocado para a lista
void forward_list_destroy(ForwardList* l);

// remove todas as ocorrências de um valor da lista
void forward_list_remove(ForwardList* l, int val);

#endif
