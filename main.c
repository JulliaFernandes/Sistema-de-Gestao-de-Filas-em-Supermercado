#include "functions.c"
#define qtdCaixas 5

// int main () {

//     int op=-1;
//     Fila clientes;
//     clientes.inicio = NULL;
//     clientes.fim = NULL;
//     clientes.numClientes = 0;
//     Fila caixas[qtdCaixas];

//     for (int i = 0; i < qtdCaixas; i++) {
//         criarCaixa(&caixas[i]);
//     }

//     while (op != 0)
//     {
//         printf("\t ### Menu ### \n");
//         printf("1- Cadastrar um cliente \n");
//         printf("2- Atender um cliente \n");
//         printf("3- Abrir caixa \n");
//         printf("4- Fechar caixa \n");
//         printf("5- Imprimir a lista de clientes em espera \n");
//         printf("6- Imprimir o status dos caixas \n");
//         printf("7- Imprimir clientes \n");
//         printf("8- Imprimir caixas \n");
//         printf("0- Sair \n");
//         printf("> ");
//         scanf("%d", &op);

//         switch (op) {
//             case 1:
//                 printf("\t ### Cadastrar um cliente ### \n");
//                 CadastroCliente(&clientes, qtdCaixas);
//                 break;
//             case 2:
//                 printf("\t ### Atender um cliente ### \n");
//                 break;
//             case 3:
//                 printf("\t ### Abrir um caixa ### \n");
//                 abrirCaixa(caixas, qtdCaixas);
//                 break;
//             case 4:
//                 printf("\t ### Fechar um caixa ### \n");
//                 fecharCaixa(caixas, qtdCaixas);
//                 break;
//             case 5:
//                 printf("\t ### Imprimir a lista de clientes em espera ### \n");
//                 break;
//             case 6:
//                 printf("\t ### Imprimir o status dos caixas ### \n");
//                 break;
//             case 7:
//                 imprimirCliente(&clientes);
//                 break;
//             case 8:
//                 imprimirCaixa(caixas, qtdCaixas);
//                 break;
//             case 0:
//                 printf("Saindo... Obrigado por usar o sistema :) \n");
//                 break;
//             default:
//                 printf("Opção inválida");
//                 break;
//         }
//     }
    



//     return 0;
// }
int main () {
    int op = -1;
    Fila caixas[qtdCaixas];

    for (int i = 0; i < qtdCaixas; i++) {
        criarCaixa(&caixas[i]);
    }

    while (op != 0) {
        printf("\t ### Menu ### \n");
        printf("1- Cadastrar um cliente \n");
        printf("2- Atender um cliente \n");
        printf("3- Abrir caixa \n");
        printf("4- Fechar caixa \n");
        printf("5- Imprimir a lista de clientes em espera \n");
        printf("6- Imprimir o status dos caixas \n");
        printf("0- Sair \n> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\t ### Cadastrar um cliente ### \n");
                CadastroCliente(caixas, qtdCaixas);
                break;
            case 2:
                // Adicione a lógica de atendimento aqui
                break;
            case 3:
                abrirCaixa(caixas, qtdCaixas);
                break;
            case 4:
                fecharCaixa(caixas, qtdCaixas);
                break;
            case 5:
                for (int i = 0; i < qtdCaixas; i++) {
                    printf("Clientes na fila do Caixa %d:\n", i + 1);
                    imprimirCliente(&caixas[i]);
                }
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
