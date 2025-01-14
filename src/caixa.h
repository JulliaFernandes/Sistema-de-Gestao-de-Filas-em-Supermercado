#ifndef CAIXA_H
#define CAIXA_H

#include "structs.h" 
#include "cliente.h"

void criarCaixa(Fila *c);  
int ProcurarCaixaAberto(Fila caixas[], int qtdCaixas);  
void abrirCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);  
void fecharCaixa(Fila caixas[], int qtdCaixas, int *contCaixasAbertos); 
void imprimirCaixa(Fila caixas[], int qtdCaixas);  
int ValidacaoCaixa(int qtdCaixas);  

#endif  

