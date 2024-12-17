#include "functions.h"

// void InserirCliente(Fila *fila, Cliente *cliente) {
//     No *novoNo = (No*) malloc(sizeof(No));

//     if (novoNo == NULL) {
//         printf("Erro ao alocar memória\n");
//         exit(1);
//     }
//     novoNo->cliente = cliente;
//     novoNo->prox = NULL;

//     // Se a fila estiver vazia ou o novo cliente tiver maior prioridade (menor número)
//     if (fila->inicio == NULL || cliente->prioridade < fila->inicio->cliente->prioridade) {
//         novoNo->prox = fila->inicio;
//         fila->inicio = novoNo;
//         if (fila->fim == NULL) {  // Se era o primeiro cliente da fila
//             fila->fim = novoNo;
//         }
//     } else {
//         // Percorre a fila para encontrar a posição correta de inserção
//         No *atual = fila->inicio;
//         while (atual->prox != NULL && atual->prox->cliente->prioridade <= cliente->prioridade) {
//             atual = atual->prox;
//         }
//         novoNo->prox = atual->prox;
//         atual->prox = novoNo;
//         if (novoNo->prox == NULL) {  // Se for o último cliente da fila
//             fila->fim = novoNo;
//         }
//     }

//     fila->numClientes++;
// }


int ValidadcaoCaixa(int qtdCaixas)  {
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

// void imprimirCliente(int qtdCaixas, Fila caixas[]) {
//     for (int i = 0; i < qtdCaixas; i++) {
//         printf("\n");
//         printf("Clientes na fila do Caixa %d:\n", i + 1);
//         No *temp = caixas[i].inicio;
//         if (temp == NULL) {
//             printf("--- SEM CLIENTE CADASTRADOS ATE O MOMENTO --- \n");
//             printf("\n");
//             continue;
//         }

//         printf("\n");
//         printf("\t ### Imprimindo clientes ### \n\n");
//         while (temp != NULL) {
//             Cliente *c = temp->cliente;
//             printf("> Nome: %s \n", c->nome);
//             printf("> CPF: %s \n", c->cpf);
//             printf("> Prioridade: %d \n", c->prioridade);
//             printf("> Quatidade de Itens: %d \n", c->numItens);
//             temp = temp->prox;  

//             printf("\n =========================================== \n");
//         }
//         printf("\n");
//     }
// }

int ConferePrioridade(int num){
    while(num != 1 && num != 2 && num != 3){
        printf("Prioridade inválida, digite novamente: \n> ");
        scanf("%d", &num);
    }
    return num;
}

// void CadastroCliente(Fila caixas[], int qtdCaixas, int *contCaixasAbertos, int *primeiroClienteInserido) {
//     printf("\t ### Cadastrar um cliente ### \n");

    

//     Cliente *novoCliente = (Cliente*) malloc(sizeof(Cliente));
//     if (novoCliente == NULL) {
//         printf("Erro ao alocar memória\n");
//         exit(1);
//     }

//     int numCaixa = ValidadcaoCaixa(qtdCaixas);
//     if (numCaixa == -1 || !caixas[numCaixa].statusCaixa) {
//         printf("Caixa %d não está aberto ou não existe.\n", numCaixa + 1);
//         free(novoCliente);
//         return;
//     }

//     // char nomeAux[100];
//     printf("Digite seu nome: \n> ");
//     // scanf("%99s", novoCliente->nome);
//     scanf(" %[^\n]%*c",novoCliente->nome); 

//     printf("Digite seu CPF: \n> ");
//     scanf("%11s", novoCliente->cpf);

//     printf("Digite sua prioridade (1 - Alta, 2 - Média, 3 - Baixa): \n> ");
//     scanf("%d", &novoCliente->prioridade);
//     novoCliente->prioridade = ConferePrioridade(novoCliente->prioridade);

//     printf("Digite o número de itens: \n> ");
//     scanf("%d", &novoCliente->numItens);

//     InserirCliente(&caixas[numCaixa], novoCliente);
//     printf("Cliente cadastrado com sucesso no Caixa %d!\n", numCaixa + 1);

//     if (!*primeiroClienteInserido) {
//         fechandoCaixasVazios(caixas, qtdCaixas, contCaixasAbertos);
//         *primeiroClienteInserido = 1;
//     }
// }


//////////////////////  <<<< CAIXA >>>> ////////////////////////////////////////////////////////
// void criarCaixa(Fila *c) {
//     c->numClientes = 0;
//     c->inicio = NULL;   
//     c->fim = NULL;
//     c->statusCaixa = true;
// }

// int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas) {
//     for (int i = 0; i < qtdCaixas; i++) {
//         if (caixas[i].statusCaixa) {
//             printf("Caixa %d está aberto.\n", i + 1);
//             return i;
//         }
//     }
//     printf("Nenhum caixa está aberto.\n");
//     return -1;
// }

// int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas) {
//     int indiceCaixa = -1;
//     int menorNumeroDeClientes = INT_MAX; // Inicializa com um valor muito alto

//     for (int i = 0; i < qtdCaixas; i++) {
//         if (caixas[i].statusCaixa) {
//             printf("Caixa %d está aberto.\n", i + 1);
//             // Verifica o número de clientes no caixa atual
//             if (caixas[i].numClientes < menorNumeroDeClientes) {
//                 menorNumeroDeClientes = caixas[i].numClientes;
//                 indiceCaixa = i;
//             }
//         }
//     }

//     if (indiceCaixa != -1) {
//         printf("O caixa com o menor número de clientes (%d clientes) é o Caixa %d.\n", menorNumeroDeClientes, indiceCaixa + 1);
//         return indiceCaixa;
//     } else {
//         printf("Nenhum caixa está aberto.\n");
//         return -1;
//     }
// }

// void abrirCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos) {
//     int numCaixa = ValidadcaoCaixa(qtdCaixas);
//     if (numCaixa == -1) {
//         return;
//     }
//     if (caixas[numCaixa].statusCaixa) {
//         printf("Caixa %d já está aberto.\n", numCaixa + 1);
//         return;
//     }
//     (*contCaixasAbertos)++; 
//     caixas[numCaixa].statusCaixa = true;
//     printf("Caixa %d aberto com sucesso.\n", numCaixa + 1);
// }

// void fecharCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos) {
//     int numCaixa = ValidadcaoCaixa(qtdCaixas);

//     printf("Qts de caixas abertos: %d\n", *contCaixasAbertos);

//     if (numCaixa == -1) {
//         return;
//     }
//     if(*contCaixasAbertos == 1){
//         printf("Não é possível fechar o único caixa aberto.\n");
//         return;
//     }
//     if (!caixas[numCaixa].statusCaixa) {
//         printf("Caixa %d já está fechado.\n", numCaixa + 1);
//         return;
//     }

//     // Fechando o caixa atual
//     caixas[numCaixa].statusCaixa = false;
//     printf("Caixa %d fechado com sucesso.\n", numCaixa + 1);

//     // Encontrar um caixa aberto para receber os clientes
//     int novoCaixaAReceberClientes = ProcurarCaixaAberto(caixas, qtdCaixas);
    
//     (*contCaixasAbertos)--; 

//     No *temp = caixas[numCaixa].inicio;
//     while (temp != NULL) {
//         Cliente *c = temp->cliente;
//         InserirCliente(&caixas[novoCaixaAReceberClientes], c);
//         temp = temp->prox;
//     }

//     // Limpando a fila do caixa que foi fechado
//     caixas[numCaixa].inicio = NULL;
//     caixas[numCaixa].fim = NULL;
//     caixas[numCaixa].numClientes = 0;
// }

// void fechandoCaixasVazios(Fila caixas[], int qtdCaixas, int *contCaixasAbertos) {
//     for (int i = 0; i < qtdCaixas; i++) {
//         if (caixas[i].statusCaixa && caixas[i].numClientes == 0) {
//             caixas[i].statusCaixa = false;
//             (*contCaixasAbertos)--;
//         }
//     }
// }


// void imprimirCaixa(Fila caixas[], int qtdCaixas) {
//     printf("\t ### Status dos Caixas ### \n");
//     for (int i = 0; i < qtdCaixas; i++) {
//         printf("> Caixa %d: %s\n", i + 1, caixas[i].statusCaixa ? "Aberto" : "Fechado");
//         printf("> Clientes na fila: %d\n\n", caixas[i].numClientes);
//     }
// }

// void RetirarCliente(Fila caixas[], int qtdCaixas){
//     int numCaixa = ValidadcaoCaixa(qtdCaixas);
//     if (numCaixa == -1) {
//         // printf("Caixa %d não existe.\n", numCaixa + 1);
//         return;
//     }
//     if(!caixas[numCaixa].statusCaixa){
//         printf("Caixa %d está fechado.\n", numCaixa + 1);
//         return;
//     }

//     if (caixas[numCaixa].inicio == NULL) {
//         printf("Não há clientes na fila do Caixa %d.\n", numCaixa + 1);
//         return;
//     }

//     printf("\t ### Atendendo cliente ### \n");

//     No *temp = caixas[numCaixa].inicio;
//     Cliente *c = temp->cliente;
//     caixas[numCaixa].inicio = temp->prox;
//     free(temp);
//     caixas[numCaixa].numClientes--;

//     printf("Cliente %s retirado do Caixa %d.\n", c->nome, numCaixa + 1);
// }


//////////////////////  <<<< FILA DE PRIORIDADE >>>> ////////////////////////////////////////////////////////
// Fila* criarFilaPrioridade() {
//     Fila* fila = (Fila*)malloc(sizeof(Fila));
//     fila->inicio = fila->fim = NULL;
//     fila->numClientes = 0;
//     return fila;
// }


// ///////////////////////////////////////////////////////////////////////////////  

// void ImprimirFilaPrioridade(Fila *fila) {
//     No *temp = fila->inicio;
//     if (temp == NULL) {
//         printf("--- SEM CLIENTE CADASTRADO ATE O MOMENTO --- \n");
//         return;
//     }

//     while (temp != NULL) {
//         Cliente *c = temp->cliente;
//         printf("> Nome: %s \n", c->nome);
//         printf("> CPF: %s \n", c->cpf);
//         printf("> Prioridade: %d \n", c->prioridade);
//         printf("> Quatidade de Itens: %d \n", c->numItens);
//         temp = temp->prox;  

//         printf("\n =================================================== \n");
//     }
    
// }

