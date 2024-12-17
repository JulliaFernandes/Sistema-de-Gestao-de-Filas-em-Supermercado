#ifndef CAIXA_H
#define CAIXA_H

#include "structs.h"  // Certifique-se de que os structs são bem definidos aqui
#include "cliente.h"

void criarCaixa(Fila *c);  // Função para criar uma nova caixa
int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas);  // Função para procurar uma caixa aberta
void abrirCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);  // Função para abrir um caixa
void fecharCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);  // Função para fechar um caixa
void imprimirCaixa(Fila caixas[], int qtdCaixas);  // Função para imprimir as caixas
int ValidacaoCaixa(int qtdCaixas);  // Função para validar caixas

#endif  // CAIXA_H

