#include "structs.c"

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


int ValidadcaoCaixa(Fila caixas[], int qtdCaixas) {
    printf("Qual caixa deseja operar? \n> ");
    int numCaixa;
    scanf("%d", &numCaixa);
    numCaixa--;

    if (numCaixa < 0 || numCaixa >= qtdCaixas) {
        printf("Caixa não existe\n");
        return -1;
    }
    return numCaixa;
}

void imprimirCliente(Fila *fila) {
    No *temp = fila->inicio;
    if (temp == NULL) {
        printf("--- SEM CLIENTE CADASTRADOS ATE O MOMENTO --- \n");
        return;
    }

    printf("\t ### Imprimindo clientes ### \n\n");
    while (temp != NULL) {
        Cliente *c = temp->cliente;
        printf("> Nome: %s \n", c->nome);
        printf("> CPF: %s \n", c->cpf);
        printf("> Prioridade: %d \n", c->prioridade);
        printf("> Quatidade de Itens: %d \n", c->numItens);
        temp = temp->prox;  

        printf("\n ------------------- \n");
    }
}

void CadastroCliente(Fila caixas[], int qtdCaixas) {
    Cliente *novoCliente = (Cliente*) malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    int numCaixa = ValidadcaoCaixa(caixas, qtdCaixas);
    if (numCaixa == -1 || !caixas[numCaixa].statusCaixa) {
        printf("Caixa %d não está aberto ou não existe.\n", numCaixa + 1);
        free(novoCliente);
        return;
    }

    printf("Digite seu nome: \n> ");
    scanf("%99s", novoCliente->nome);

    printf("Digite seu CPF: \n> ");
    scanf("%11s", novoCliente->cpf);

    printf("Digite sua prioridade (1 - Alta, 2 - Média, 3 - Baixa): \n> ");
    scanf("%d", &novoCliente->prioridade);

    printf("Digite o número de itens: \n> ");
    scanf("%d", &novoCliente->numItens);

    InserirCliente(&caixas[numCaixa], novoCliente);
    printf("Cliente cadastrado com sucesso no Caixa %d!\n", numCaixa + 1);
}


//////////////////////  <<<< CAIXA >>>> ////////////////////////////////////////////////////////
void criarCaixa(Fila *c) {
    c->numClientes = 0;
    c->inicio = NULL;   
    c->fim = NULL;
    c->statusCaixa = false;
}

int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas) {
    for (int i = 0; i < qtdCaixas; i++) {
        if (caixas[i].statusCaixa) {
            printf("Caixa %d está aberto.\n", i + 1);
            return i;
        }
    }
    printf("Nenhum caixa está aberto.\n");
    return -1;
}

void abrirCaixa(Fila caixas[], int qtdCaixas) {
    int numCaixa = ValidadcaoCaixa(caixas, qtdCaixas);
    if (numCaixa == -1) {
        return;
    }
    if (caixas[numCaixa].statusCaixa) {
        printf("Caixa %d já está aberto.\n", numCaixa + 1);
        return;
    }
    caixas[numCaixa].statusCaixa = true;
    printf("Caixa %d aberto com sucesso.\n", numCaixa + 1);
}

void fecharCaixa(Fila caixas[], int qtdCaixas) {
    int numCaixa = ValidadcaoCaixa(caixas, qtdCaixas);
    if (numCaixa == -1) {
        return;
    }
    if (!caixas[numCaixa].statusCaixa) {
        printf("Caixa %d já está fechado.\n", numCaixa + 1);
        return;
    }

    // Fechando o caixa atual
    caixas[numCaixa].statusCaixa = false;
    printf("Caixa %d fechado com sucesso.\n", numCaixa + 1);

    // Encontrar um caixa aberto para receber os clientes
    int novoCaixaAReceberClientes = ProcurarCaixaAberto(caixas, qtdCaixas);
    
    // Se não houver caixa aberto, tentar abrir um novo
    if (novoCaixaAReceberClientes == -1) {
        printf("Nenhum caixa aberto para receber os clientes.\n");
        printf("Abrindo um novo caixa.\n");
        abrirCaixa(caixas, qtdCaixas);
        novoCaixaAReceberClientes = ProcurarCaixaAberto(caixas, qtdCaixas);  // Tentar encontrar de novo
    }
    
    // Verificar se encontramos um caixa válido para receber os clientes
    if (novoCaixaAReceberClientes == -1) {
        printf("Erro: Não há caixas abertos disponíveis para receber os clientes.\n");
        return;
    }

    // Transferindo clientes para o novo caixa
    No *temp = caixas[numCaixa].inicio;
    while (temp != NULL) {
        Cliente *c = temp->cliente;
        InserirCliente(&caixas[novoCaixaAReceberClientes], c);
        temp = temp->prox;
    }

    // Limpando a fila do caixa que foi fechado
    caixas[numCaixa].inicio = NULL;
    caixas[numCaixa].fim = NULL;
    caixas[numCaixa].numClientes = 0;
}


void imprimirCaixa(Fila caixas[], int qtdCaixas) {
    printf("\t ### Status dos Caixas ### \n");
    for (int i = 0; i < qtdCaixas; i++) {
        printf("> Caixa %d: %s\n", i + 1, caixas[i].statusCaixa ? "Aberto" : "Fechado");
        printf("> Clientes na fila: %d\n\n", caixas[i].numClientes);
    }
}



//////////////////////  <<<< FILA DE PRIORIDADE >>>> ////////////////////////////////////////////////////////
Fila* criarFilaPrioridade() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    fila->numClientes = 0;
    return fila;
}


///////////////////////////////////////////////////////////////////////////////  

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

        printf("\n ------------------- \n");
    }
    
}


