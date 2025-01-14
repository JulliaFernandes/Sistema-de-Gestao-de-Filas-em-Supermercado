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

int validarCPF(const char *cpf) {
    int length = strlen(cpf);

    // tem de ser 11
    if (length != 11) {
        return 0;
    }

    for (int i = 0; i < length; i++) { // ter de ser tudo numero
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }
    return 1; // CPF válido
}

void InserirCliente(Fila *fila, Cliente *cliente) {
    No *novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    novoNo->cliente = cliente;
    novoNo->prox = NULL;

    // se não tiver ngn a fila ou o cliente tem maior prioridade
    if (fila->inicio == NULL || cliente->prioridade < fila->inicio->cliente->prioridade) {
        novoNo->prox = fila->inicio;
        fila->inicio = novoNo;
        if (fila->fim == NULL) {
            fila->fim = novoNo;
        }
    } else {
        No *atual = fila->inicio;
        while (atual->prox != NULL && atual->prox->cliente->prioridade <= cliente->prioridade) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
        if (novoNo->prox == NULL) {  // se for o ultimo na fila
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
    if(numCaixa == -1){
    // if (numCaixa == -1 || !caixas[numCaixa].statusCaixa) {
        // printf("Caixa %d não está aberto ou não existe.\n", numCaixa + 1);
        // printf("Caixa não existe");
        free(novoCliente);
        return;
    }
    if(!caixas[numCaixa].statusCaixa){
        printf("Caixa %d está fechado.\n", numCaixa + 1);
        free(novoCliente);
        return;
    }

    printf("Digite seu nome: \n> ");
    scanf(" %[^\n]%*c",novoCliente->nome); //ele vai ler tudo ate encontrar um \n mas vai descartar o \n depois, isso por causa do *c

    do {
        printf("Digite seu CPF (apenas números, exatamente 11 dígitos): \n> ");
        scanf("%11s", novoCliente->cpf);

        char c;
        while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer 

        if (!validarCPF(novoCliente->cpf)) {
            printf("CPF inválido! O CPF deve conter exatamente 11 dígitos numéricos.\n");
        }
    } while (!validarCPF(novoCliente->cpf));

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

