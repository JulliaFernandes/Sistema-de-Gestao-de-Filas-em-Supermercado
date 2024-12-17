#ifndef FILA_H
#define FILA_H

#include "structs.h"


void fechandoCaixasVazios(Fila caixas[], int qtdCaixas, int *contCaixasAbertos);
int ConferePrioridade(int num);
Fila* criarFilaPrioridade();
void ImprimirFilaPrioridade(Fila *fila);

#endif  // FILA_H
