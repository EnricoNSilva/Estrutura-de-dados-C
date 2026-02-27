#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct Celula{

    struct Celula *anterior;

    struct Celula *proximo;

    int valor;

}Celula;



typedef struct LDDE{

    Celula *primeiro;

    int qtde;

}LDDE;



LDDE *inicializa_lista(){

    LDDE *lista = malloc(sizeof(LDDE));

    lista->primeiro = NULL;

    lista->qtde = 0;

    return lista;

}



Celula *inicializa_celula(int valor){

    Celula *celula = malloc(sizeof(Celula));

    celula->anterior = NULL;

    celula->proximo = NULL;

    celula->valor = valor;

    return celula;

}



void inserir(LDDE *lista, int valor) {

    Celula *novo = inicializa_celula(valor);

    if (lista->primeiro == NULL) {

        lista->primeiro = novo;

        lista->qtde++;

        return;

    }



    Celula *atual = lista->primeiro;



    /* inserir no começo */

    if (valor < atual->valor) {

        novo->proximo = atual;

        atual->anterior = novo;

        lista->primeiro = novo;

        lista->qtde++;

        return;

    }



    /* percorre para encontrar posição */

    while (atual->proximo != NULL && atual->proximo->valor <= valor) {

        atual = atual->proximo;

    }



    /* inserir no fim */

    if (atual->proximo == NULL && atual->valor <= valor) {

        atual->proximo = novo;

        novo->anterior = atual;

        lista->qtde++;

        return;

    }



    /* inserir entre atual e atual->proximo */

    Celula *next = atual->proximo;

    novo->proximo = next;

    novo->anterior = atual;

    atual->proximo = novo;

    if (next != NULL) next->anterior = novo;

    lista->qtde++;

}



void imprimir_crescente(LDDE *lista){

    Celula *atual = lista->primeiro;

    while(atual != NULL){

        printf("%d ", atual->valor);

        atual = atual->proximo;

    }

    printf("\n");

}



void imprimir_decrescente(LDDE *lista){

    Celula *atual = lista->primeiro;

    Celula *anterior = NULL;

    while(atual != NULL){

        anterior = atual;

        atual = atual->proximo;

    }

    atual = anterior;

    while(atual != NULL){

        printf("%d ", atual->valor);

        atual = atual->anterior;

    }

    printf("\n");

}



Celula *buscar(LDDE *lista, int valor){

    Celula *atual = lista->primeiro;

    while(atual != NULL && atual->valor != valor){

        atual = atual->proximo;

    }

    return atual;

}



void remover(LDDE *lista, int valor) {

    Celula *alvo = buscar(lista, valor);

    if (alvo == NULL) return;



    if (alvo->anterior != NULL) {

        alvo->anterior->proximo = alvo->proximo;

    } else {

        /* era o primeiro */

        lista->primeiro = alvo->proximo;

    }



    if (alvo->proximo != NULL) {

        alvo->proximo->anterior = alvo->anterior;

    }



    free(alvo);

    lista->qtde--;

}



int main(void) {

  LDDE *lista = inicializa_lista();

    int in[] = {2, 3, 9, 6, 7, 4, 1, 8, 0, 5};

    int out[] = {0, 9, 1, 8, 5, 5, 6, 2, 3, 4, 7};

    int len_in = sizeof(in) / sizeof(int);

    int len_out = sizeof(out) / sizeof(int);

    for(int i = 0; i < len_in; i ++){

        inserir(lista, in[i]);

        imprimir_crescente(lista);

        imprimir_decrescente(lista);

    }

    for(int j = 0; j < len_out; j++){

        remover(lista, out[j]);

        imprimir_crescente(lista);

        imprimir_decrescente(lista);    

    }
    Sleep(99999999);
  return 0;

}

