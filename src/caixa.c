#include "caixa.h"

void criarCaixa(Fila *c) {
    c->numClientes = 0;
    c->inicio = NULL;   
    c->fim = NULL;
    c->statusCaixa = true;
}

int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas) {
    int indiceCaixa = -1;
    int menorNumeroDeClientes = INT_MAX; // inicia com um valor muito alto

    for (int i = 0; i < qtdCaixas; i++) {
        if (caixas[i].statusCaixa) {
            // printf("Caixa %d está aberto.\n", i + 1);
            // Verifica o número de clientes no caixa atual
            if (caixas[i].numClientes < menorNumeroDeClientes) {
                menorNumeroDeClientes = caixas[i].numClientes;
                indiceCaixa = i;
            }
        }
    }

    if (indiceCaixa != -1) {
        // printf("O caixa com o menor número de clientes (%d clientes) é o Caixa %d.\n", menorNumeroDeClientes, indiceCaixa + 1);
        printf("Clientes foram transferidos para o Caixa %d.\n", indiceCaixa + 1);
        return indiceCaixa;
    } else {
        printf("Nenhum caixa está aberto.\n");
        return -1;
    }
}

void abrirCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos) {
    int numCaixa = ValidacaoCaixa(qtdCaixas);
    if (numCaixa == -1) {
        return;
    }
    if (caixas[numCaixa].statusCaixa) {
        printf("Caixa %d já está aberto.\n", numCaixa + 1);
        return;
    }
    (*contCaixasAbertos)++; 
    caixas[numCaixa].statusCaixa = true;
    printf("Caixa %d aberto com sucesso.\n", numCaixa + 1);
}

void fecharCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos) {
    int numCaixa = ValidacaoCaixa(qtdCaixas);

    // printf("Qts de caixas abertos: %d\n", *contCaixasAbertos);

    if (numCaixa == -1) {
        return;
    }
    if (!caixas[numCaixa].statusCaixa) {
        printf("Caixa %d já está fechado.\n", numCaixa + 1);
        return;
    }
    if(*contCaixasAbertos == 1){
        printf("Não é possível fechar o único caixa aberto.\n");
        return;
    }

    // Fechando o caixa atual
    caixas[numCaixa].statusCaixa = false;

    // Encontrar um caixa aberto para receber os clientes
    int novoCaixaAReceberClientes = ProcurarCaixaAberto(caixas, qtdCaixas);
    printf("Caixa %d fechado com sucesso.\n", numCaixa + 1);
    
    (*contCaixasAbertos)--; 

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

int ValidacaoCaixa(int qtdCaixas)  {
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