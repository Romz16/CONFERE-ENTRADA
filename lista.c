#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
int TListaInicia(TLista *pLista) {
    pLista->cabeca = malloc(sizeof(TCelula));
    pLista->cabeca->prox = NULL;
    return 1;
}

//Retorna se a lista esta vazia
int TListaEhVazia(TLista *pLista) {
    if(pLista->cabeca->prox == NULL){
        return 1; //é uma lista vazia
    }
    return 0; //a lista não é vazia
}

// Insere um item no inicio da lista
int TListaInserePrimeiro(TLista *pLista, TItem item) {

    TCelula *primeira = malloc(sizeof(TCelula));//alocando memoria para celula
    if(primeira == NULL)
        return 0;
    primeira->item = item; //atribuindo valor a celula a ser add
    primeira->prox = pLista->cabeca->prox; //referenciando o segundo item na lista como proximo ao primeiro
    pLista->cabeca->prox = primeira; //atualizando na cabeça a primeira celula
    return 1;
}

// Retira o primeiro item da lista
int TListaRetiraPrimeiro(TLista *pLista, TItem *pItem) {

    if(TListaEhVazia(pLista) == 1)
        return 0 ;
    TCelula *aux = pLista->cabeca->prox;
    pLista->cabeca->prox = pLista->cabeca->prox->prox;
    free(aux);
    return 1;
}

// Imprime os elementos da lista
void TListaImprime(TLista *pLista) {
    TCelula *imprime = malloc(sizeof(TCelula));
    imprime->prox = pLista->cabeca->prox;
    do{
        printf("%c", imprime->item);
        imprime = imprime->prox;
    }while(imprime != NULL);
    free(imprime);
}

//Remove cada elemento de uma lista e libera a memória
void TListaEsvazia(TLista *pLista) {
    TCelula *aux = pLista->cabeca;
    do{
        if(pLista->cabeca->prox == NULL)
            break;
        pLista->cabeca->prox = pLista->cabeca->prox->prox;
        free(aux->prox);
    }while(aux!=NULL);
}
