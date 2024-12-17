#ifndef CLIENTE_H
#define CLIENTE_H

#include "structs.h"
#include "fila.h"
#include "caixa.h"


void imprimirCliente(int qtdCaixas, Fila caixas[]);
void InserirCliente(Fila *fila, Cliente *cliente);
void CadastroCliente(Fila caixas[], int qtdCaixas, int *contCaixasAbertos, int *primeiroClienteInserido);
void RetirarCliente(Fila caixas[], int qtdCaixas);

#endif  // CLIENTE_H
