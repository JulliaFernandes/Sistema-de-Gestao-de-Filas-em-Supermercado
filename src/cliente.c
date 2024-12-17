#include "cliente.h"

void imprimirCliente(int qtdCaixas, Fila caixas[]) {
    for (int i = 0; i < qtdCaixas; i++) {
        printf("\n");
        printf("Clientes na fila do Caixa %d:\n", i + 1);
        No *temp = caixas[i].inicio;
        if (temp == NULL) {
            printf("--- SEM CLIENTE CADASTRADOS ATE O MOMENTO --- \n");
            printf("\n");
            continue;
        }

        printf("\n");
        printf("\t ### Imprimindo clientes ### \n\n");
        while (temp != NULL) {
            Cliente *c = temp->cliente;
            printf("> Nome: %s \n", c->nome);
            printf("> CPF: %s \n", c->cpf);
            printf("> Prioridade: %d \n", c->prioridade);
            printf("> Quatidade de Itens: %d \n", c->numItens);
            temp = temp->prox;  

            printf("\n =========================================== \n");
        }
        printf("\n");
    }
}

void InserirCliente(Fila *fila, Cliente *cliente) {
    No *novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    novoNo->cliente = cliente;
    novoNo->prox = NULL;

    // Se a fila estiver vazia ou o novo cliente tiver maior prioridade (menor número)
    if (fila->inicio == NULL || cliente->prioridade < fila->inicio->cliente->prioridade) {
        novoNo->prox = fila->inicio;
        fila->inicio = novoNo;
        if (fila->fim == NULL) {  // Se era o primeiro cliente da fila
            fila->fim = novoNo;
        }
    } else {
        // Percorre a fila para encontrar a posição correta de inserção
        No *atual = fila->inicio;
        while (atual->prox != NULL && atual->prox->cliente->prioridade <= cliente->prioridade) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
        if (novoNo->prox == NULL) {  // Se for o último cliente da fila
            fila->fim = novoNo;
        }
    }

    fila->numClientes++;
}

void CadastroCliente(Fila caixas[], int qtdCaixas, int *contCaixasAbertos, int *primeiroClienteInserido) {
    printf("\t ### Cadastrar um cliente ### \n");

    

    Cliente *novoCliente = (Cliente*) malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    int numCaixa = ValidacaoCaixa(qtdCaixas);
    if (numCaixa == -1 || !caixas[numCaixa].statusCaixa) {
        printf("Caixa %d não está aberto ou não existe.\n", numCaixa + 1);
        free(novoCliente);
        return;
    }

    // char nomeAux[100];
    printf("Digite seu nome: \n> ");
    // scanf("%99s", novoCliente->nome);
    scanf(" %[^\n]%*c",novoCliente->nome); 

    printf("Digite seu CPF: \n> ");
    scanf("%11s", novoCliente->cpf);

    printf("Digite sua prioridade (1 - Alta, 2 - Média, 3 - Baixa): \n> ");
    scanf("%d", &novoCliente->prioridade);
    novoCliente->prioridade = ConferePrioridade(novoCliente->prioridade);

    printf("Digite o número de itens: \n> ");
    scanf("%d", &novoCliente->numItens);

    InserirCliente(&caixas[numCaixa], novoCliente);
    printf("Cliente cadastrado com sucesso no Caixa %d!\n", numCaixa + 1);

    if (!*primeiroClienteInserido) {
        fechandoCaixasVazios(caixas, qtdCaixas, contCaixasAbertos);
        *primeiroClienteInserido = 1;
    }
}

void RetirarCliente(Fila caixas[], int qtdCaixas){
    int numCaixa = ValidacaoCaixa(qtdCaixas);
    if (numCaixa == -1) {
        // printf("Caixa %d não existe.\n", numCaixa + 1);
        return;
    }
    if(!caixas[numCaixa].statusCaixa){
        printf("Caixa %d está fechado.\n", numCaixa + 1);
        return;
    }

    if (caixas[numCaixa].inicio == NULL) {
        printf("Não há clientes na fila do Caixa %d.\n", numCaixa + 1);
        return;
    }

    printf("\t ### Atendendo cliente ### \n");

    No *temp = caixas[numCaixa].inicio;
    Cliente *c = temp->cliente;
    caixas[numCaixa].inicio = temp->prox;
    free(temp);
    caixas[numCaixa].numClientes--;

    printf("Cliente %s retirado do Caixa %d.\n", c->nome, numCaixa + 1);
}

