#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listas.h"

void clrscr()
{
    system("@cls||clear");
}

Cliente solicitarInfosCliente() {

    Cliente c;
    
    printf("\nCADASTRO CLIENTE\n");
    printf("\nNome: ");scanf("%s", c.nome);
    printf("\nData de nascimento: ");
    printf("\nDia: ");scanf("%d", &c.data.dia);
    printf("Mês: ");scanf("%d", &c.data.mes);
    printf("Ano: ");scanf("%d", &c.data.ano);
    printf("\nE-mail: ");scanf("%s", c.email);
    printf("Telefone: ");scanf("%ld", &c.telefone);
    printf("Endereço: ");
    printf("\nRua: ");scanf("%d", &c.endereco.rua);
    printf("Número: ");scanf("%d", &c.endereco.numero);
    printf("Bairro: ");scanf("%s", c.endereco.bairro);
    printf("UF: ");scanf("%s", c.endereco.uf);
    printf("\n\nCADASTRO REALIZADO.");
    getchar();
    return c;
}



void imprimirClientes(Cliente c) {
    printf("\nNome: %s", c.nome);
    printf("\nData de nascimento: %d/%d/%d", c.data.dia, c.data.mes,c.data.ano);
    printf("\nE-mail: %s", c.email);
    printf("\nTelefone: %ld", c.telefone);
    printf("\nEndereço:\nRua: %d\nNúmero: %d\nBairro: %s\nUF: %s", c.endereco.rua, c.endereco.numero, c.endereco.bairro, c.endereco.uf);
}

void inserir_no_inicio(No **listaClientes, Cliente cliente){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->cliente = cliente;
        novo->proximo = *listaClientes;
        *listaClientes = novo;
    }
    else
        printf("Erro ao alocar memória.\n");
}
//
void inserir_no_fim(No **listaClientes, Cliente cliente){
    No *aux, *novo = malloc(sizeof(No));

    if (novo){
        novo->cliente = cliente;
        novo->proximo = NULL;

        //é o primeiro?
        if (*listaClientes == NULL)
            *listaClientes = novo;
        else{
            aux = *listaClientes;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo; 
        }
    }
    else
        printf("Erro ao alocar memória.");
}

/*void inserir_no_meio(No **listaCliente, Cliente cliente, Cliente ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->cliente = cliente;
        //é o primeiro?
        if(*listaCliente == NULL)
        {
            novo->proximo = NULL;
            *listaCliente = novo;
        }else{
            aux = *listaCliente;
            while(aux->cliente != ant && aux->proximo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }else{
        printf("\nErro ao alocar memória.");
    }  
}*/

void imprimir(No *no){
    printf("\n-------- LISTA CLIENTES ----------");
    while (no)
    {
        imprimirClientes(no->cliente);
        printf("\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------");
}


int menuCliente(){
    int areaCliente;
    printf("\n---------- ÁREA CLIENTE ----------\n");
    printf("\n0 - Sair\n1 - Cadastrar Cliente\n2 - Lista Clientes\n");
    printf("\n----------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaCliente);
    return areaCliente;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opcao, areaCliente;
    No *listaCliente = NULL;
    Cliente c;
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

        case 2:

            break; 
        case 3:

            break;

        default:
            printf("Opção inválida.");
            break;
        }

    } while (opcao != 0);

    return 0;
}
