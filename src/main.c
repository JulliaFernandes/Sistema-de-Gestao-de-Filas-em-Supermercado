#include "cliente.h"
#include "caixa.h"
#include "fila.h"
#include "includes.h"

// #include "structs.h"

#define qtdCaixas 5

int main () {
    int op = -1;
    Fila caixas[qtdCaixas];
    // char input[10];
    int contCaixasAbertos=5;
    int primeiroClienteInserido = 0;

    for (int i = 0; i < qtdCaixas; i++) {
        criarCaixa(&caixas[i]);
    }


    while (op != 0) {
        printf(CYAN "\n\t╔════════════════════════════════════════╗\n" RESET);
        printf(CYAN "\t║" RESET BOLD "               ### Menu ###           " RESET CYAN "  ║\n" RESET);
        printf(CYAN "\t╠════════════════════════════════════════╣\n" RESET);
        printf(CYAN "\t║" RESET " 1 - Cadastrar um cliente             " CYAN "  ║\n" RESET);
        printf(CYAN "\t║" RESET " 2 - Atender um cliente               " CYAN "  ║\n" RESET);
        printf(CYAN "\t║" RESET " 3 - Abrir caixa                      " CYAN "  ║\n" RESET);
        printf(CYAN "\t║" RESET " 4 - Fechar caixa                     " CYAN "  ║\n" RESET);
        printf(CYAN "\t║" RESET " 5 - Imprimir lista de clientes        " CYAN " ║\n" RESET);
        printf(CYAN "\t║" RESET " 6 - Imprimir status dos caixas        " CYAN " ║\n" RESET);
        printf(CYAN "\t║" RESET " 0 - Sair                             " CYAN "  ║\n" RESET);
        printf(CYAN "\t╚════════════════════════════════════════╝\n" RESET);
        printf(YELLOW " > " RESET);

        if (scanf("%d", &op) != 1) {  // Verifica se a leitura foi bem-sucedida
            printf(RED "Entrada inválida! Por favor, digite um número.\n" RESET);
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            op = -1;         // Reseta a variável para manter o loop
            continue;        // Volta ao início do loop para nova entrada
        }

        switch (op) {
            case 1:
                CadastroCliente(caixas, qtdCaixas, &contCaixasAbertos, &primeiroClienteInserido);
                break;
            case 2:
                RetirarCliente(caixas, qtdCaixas);
                break;
            case 3:
                abrirCaixa(caixas, qtdCaixas, &contCaixasAbertos);
                break;
            case 4:
                fecharCaixa(caixas, qtdCaixas, &contCaixasAbertos);
                break;
            case 5:
                imprimirCliente(qtdCaixas, caixas);
                break;
            case 6:
                imprimirCaixa(caixas, qtdCaixas);
                break;
            case 0:
                printf("Saindo... Obrigado por usar o sistema :) \n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }
    return 0;
}
