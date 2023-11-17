#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FuncLista.c"


int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opcao, areaCliente, areaFuncionario, areaServico;
    No   *listaCliente = NULL;
    NoF  *listaFunc = NULL;
    NoS  *listaServ = NULL;
    NoSp *listaServPrest = NULL;
    Cliente c; 
    Funcionarios f;
    Servicos s;
    ServicoPrestado sp;
    char buscaUF[3];
    int buscaCod;
    No *clienteBusca;
    
    do
    {
        printf("\n0 - Sair\n1 - Área Clientes\n2 - Área Funcionários\n3 - Área Serviços\n4 - Lava-Jato");
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
                case 3:
                    printf("\nDigite um estado: "); scanf("%s", buscaUF);
                    clienteBusca = buscaCliente(&listaCliente, buscaUF);
                    if (clienteBusca)
                    {
                        printf("\nNenhum elemento encontrado.");
                    }
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
                    f.codFuncionario = codRegistro();
                    inserir_no_fim_func(&listaFunc, f);
                    break;
                case 2:
                    imprimirF(listaFunc);
                    break;
                case 3:
                    printf("Código do Servico:"); scanf("%d", &buscaCod);
                    buscaFuncTipo(&listaServPrest, buscaCod);
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
                    s.codServico = codRegistro();       
                    inserir_no_fim_serv(&listaServ, s);
                    break;
                case 2:
                    imprimirS(listaServ);
                    break;
                case 3:
                    sp = solicitarInfosServicosPrestados();
                    buscaCod = sp.funcionarioPrestador.codFuncionario;
                    Funcionarios *funcBusca = buscaFuncionario(&listaFunc, &buscaCod);
                    if(funcBusca)
                        sp.funcionarioPrestador = *funcBusca;
                    else
                        printf("ERRO: Funcionário não encontrado.\n");
                    buscaCod = sp.clienteAtendido.cpf;
                    Cliente *cliBusca = buscaClienteCpf(&listaCliente, &buscaCod);
                    if(cliBusca)
                        sp.clienteAtendido = *cliBusca;
                    else
                        printf("ERRO: Cliente não encontrado.\n");
                    buscaCod = sp.servicoPrestado.codServico;
                    Servicos *servBusca = buscaServicoCod(&listaServ, &buscaCod);
                    if(servBusca)
                        sp.servicoPrestado = *servBusca;
                    else
                        printf("ERRO: Serviço não especificado.\n");
                    inserir_servicos_prestados(&listaServPrest, sp);
                    break;
                case 4:
                    imprimirSp(listaServPrest);
                    break;
                default:
                    printf("Opção inválida.");
                    break;
                }
            } while (areaServico != 0);
            break;
        case 4:

            break;
        default:
            printf("Opção inválida.");
            break;
        }

    } while (opcao != 0);

    return 0;
}
