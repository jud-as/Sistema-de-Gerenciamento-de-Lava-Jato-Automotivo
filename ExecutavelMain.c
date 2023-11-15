#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FuncLista.h"


int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opcao, areaCliente, areaFuncionario, areaServico;
    No  *listaCliente = NULL;
    NoF *listaFunc = NULL;
    NoS *listaServ = NULL;
    Cliente c; 
    Funcionarios f;
    Servicos s;
    do
    {
        printf("\n0 - Sair\n1 - Área Clientes\n2 - Área Funcionários\n3 - Área Serviços");
        printf("\n\nOPÇÃO: ");
        scanf("%d", &opcao);
        getchar();
        clrscr();
        switch (opcao)
        {
        case 0:
            break;
            
        case 1:
            do
            {
                areaCliente = menuCliente();
                switch (areaCliente)
                {
                case 0:
                    
                    break;
                case 1:
                    c = solicitarInfosCliente();
                    inserir_no_fim(&listaCliente, c);
                    break;
                case 2:
                    imprimir(listaCliente);
                    break;
                default:
                    printf("Opção inválida.");
                    break;
                }
            }while(areaCliente != 0);
            break;
        case 2:
             do
            {
                areaFuncionario = menuFuncionario();
                switch (areaFuncionario)
                {
                case 0:
                    
                    break;
                case 1:
                    f = solicitarInfosFuncionarios();
                    inserir_no_fim_func(&listaFunc, f);
                    break;
                case 2:
                    imprimirF(listaFunc);
                    break;
                default:
                    printf("Opção inválida.");
                    break;
                }
            }while(areaFuncionario != 0);
            break; 
        case 3:
            do
            {
                areaServico = menuServico();
                switch (areaServico)
                {
                case 0:
                    
                    break;
                case 1:
                    s = solicitarInfosServicos();
                    inserir_no_fim_serv(&listaServ, s);
                    break;
                case 2:
                    imprimirS(listaServ);
                    break;
                default:
                    printf("Opção inválida.");
                    break;
                }
            } while (areaServico != 0);
            break;

        default:
            printf("Opção inválida.");
            break;
        }

    } while (opcao != 0);

    return 0;
}
