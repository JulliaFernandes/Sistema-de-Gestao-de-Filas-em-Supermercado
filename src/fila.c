#include "fila.h"

void fechandoCaixasVazios(Fila caixas[], int qtdCaixas, int *contCaixasAbertos) {
    for (int i = 0; i < qtdCaixas; i++) {
        if (caixas[i].statusCaixa && caixas[i].numClientes == 0) {
            caixas[i].statusCaixa = false;
            (*contCaixasAbertos)--;
        }
    }
}

int ConferePrioridade(int num){
    while(num != 1 && num != 2 && num != 3){
        printf("Prioridade inválida, digite novamente: \n> ");
        scanf("%d", &num);
    }
    return num;
}

Fila* criarFilaPrioridade() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    fila->numClientes = 0;
    return fila;
} 

void ImprimirFilaPrioridade(Fila *fila) {
    No *temp = fila->inicio;
    if (temp == NULL) {
        printf("--- SEM CLIENTE CADASTRADO ATE O MOMENTO --- \n");
        return;
    }

    while (temp != NULL) {
        Cliente *c = temp->cliente;
        printf("> Nome: %s \n", c->nome);
        printf("> CPF: %s \n", c->cpf);
        printf("> Prioridade: %d \n", c->prioridade);
        printf("> Quatidade de Itens: %d \n", c->numItens);
        temp = temp->prox;  

        printf("\n =================================================== \n");
    }
    
}