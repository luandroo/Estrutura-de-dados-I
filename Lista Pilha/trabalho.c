#include<stdlib.h>
#include<stdio.h>
#include "vetorP.h"

vetorP* criarPilha() {
    vetorP* pilha = malloc(sizeof(*pilha));
    if (pilha == NULL) return NULL;
    pilha->topo = 0;
    return pilha;
}

int liberarPilha(vetorP* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    free(pilha);
    pilha = NULL;
    return OK;
}

int estahCheia(vetorP* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (pilha->topo == TAM_MAX) return TRUE;
    return FALSE;
}

int estahVazia(vetorP* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (pilha->topo == 0) return TRUE;
    return FALSE;
}

int empilhar(int item, vetorP* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahCheia(pilha))
        return ESTRUTURA_CHEIA;

    pilha->itens[pilha->topo] = item;
    pilha->topo++;
    return OK;
}

int desempilhar(vetorP* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    *item = pilha->itens[pilha->topo - 1];
    pilha->topo--;
    return OK;
}

int obterTopo(vetorP* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    *item = pilha->itens[pilha->topo - 1];
    return OK;
}