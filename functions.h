#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include "structs.h"
#include "includes.h"



void InserirCliente(Fila *fila, Cliente *cliente);
int ValidadcaoCaixa(int qtdCaixas);
void imprimirCliente(int qtdCaixas, Fila caixas[]);
int ConferePrioridade(int num);
void CadastroCliente(Fila caixas[], int qtdCaixas, int *contCaixasAbertos, int *primeiroClienteInserido);
void criarCaixa(Fila *c);
int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas);
void abrirCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);
void fecharCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);
void fechandoCaixasVazios(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);
void imprimirCaixa(Fila caixas[], int qtdCaixas);
void RetirarCliente(Fila caixas[], int qtdCaixas);




#endif