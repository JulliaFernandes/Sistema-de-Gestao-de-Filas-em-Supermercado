#ifndef STRUCTS_H
#define STRUCTS_H

#include "includes.h"  // Certifique-se que este arquivo existe
// #include "caixa.h"
// #include "cliente.h"
// #include "fila.h"

typedef struct Cliente {
    char nome[100];
    char cpf[12];  // C1 dígitos + '\0'
    int prioridade;
    int numItens;
} Cliente;

typedef struct Caixa {
    int numClientes;
    bool statusCaixa;
} Caixa;

// typedef struct FilaPrioridade {
//     Caixa *inicio;
//     Caixa *fim;
//     int numCaixas;
// } FilaPrioridade;

typedef struct No {
    Cliente *cliente;
    struct No *prox;  
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
    int numClientes;
    bool statusCaixa;
} Fila;

#endif  // STRUCTS_H
