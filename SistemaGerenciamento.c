#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

void clrscr()
{
    system("@cls||clear");
}


Cliente solicitarInfosCliente(){
    clrscr();
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

Funcionarios solicitarInfosFuncionarios(){
    clrscr();
    Funcionarios c;
    
    printf("\nCADASTRO FUNCIONÁRIO\n");
    printf("\nNome: ");scanf("%s", c.nome);
    printf("\nData de nascimento: ");
    printf("\nDia: ");scanf("%d", &c.data.dia);
    printf("Mês: ");scanf("%d", &c.data.mes);
    printf("Ano: ");scanf("%d", &c.data.ano);
    printf("\nE-mail: ");scanf("%s", c.email);
    printf("\nConta Bancária: ");
    printf("\nNúmero da Agência: ");scanf("%d", &c.contaBancaria.NumeroAgencia);
    printf("Número da Conta: ");scanf("%d", &c.contaBancaria.NumeroConta);
    printf("Digito de Verificação: ");scanf("%d", &c.contaBancaria.DigitoVerf);
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

Servicos solicitarInfosServicos(){
    clrscr();
    Servicos s;

    printf("\nCADASTRO SERVIÇO:\n");
    printf("\nNome Serviço: ");scanf("%s", s.nomeServico);
    printf("Descrição do Serviço: ");scanf("%s", s.descricao);
    printf("Valor do Serviço: ");scanf("%f", &s.valor);

    return s;
}

void imprimirClientes(Cliente c){
    printf("\nNome: %s", c.nome);
    printf("\nData de nascimento: %d/%d/%d", c.data.dia, c.data.mes,c.data.ano);
    printf("\nE-mail: %s", c.email);
    printf("\nTelefone: %ld", c.telefone);
    printf("\nEndereço:\nRua: %d\nNúmero: %d\nBairro: %s\nUF: %s", c.endereco.rua, c.endereco.numero, c.endereco.bairro, c.endereco.uf);
}

void imprimirFuncionarios(Funcionarios c){
    printf("\nNome: %s", c.nome);
    printf("\nData de nascimento: %d/%d/%d", c.data.dia, c.data.mes,c.data.ano);
    printf("\nE-mail: %s", c.email);
    printf("\nConta Bancária:\nNumero da Agência: %d\nNumero da Conta: %d\nDigito de Verificação: %d\n", c.contaBancaria.NumeroAgencia, c.contaBancaria.NumeroConta, c.contaBancaria.DigitoVerf);
    printf("\nTelefone: %ld", c.telefone);
    printf("\nEndereço:\nRua: %d\nNúmero: %d\nBairro: %s\nUF: %s", c.endereco.rua, c.endereco.numero, c.endereco.bairro, c.endereco.uf);
}

void imprimirServicos(Servicos s){
    printf("\nNome: %s", s.nomeServico);
    printf("\nDescrição: %s", s.descricao);
    printf("\nValor: %.2f", s.valor);
}

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

void inserir_no_fim_func(NoF **listaFunc, Funcionarios funcionarios){
    NoF *aux, *novo = malloc(sizeof(NoF));

    if (novo)
    {
        novo->funcionarios = funcionarios;
        novo->proximo = NULL;

        //é o primeiro?
        if (*listaFunc == NULL)
            *listaFunc = novo;
        else{
            aux = *listaFunc;
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

void inserir_no_fim_serv(NoS **listaServ, Servicos servicos){
    NoS *aux, *novo = malloc(sizeof(NoS));
    if (novo)
    {
        novo->servicos = servicos;
        novo->proximo = NULL;

        if (*listaServ == NULL)
        {
            *listaServ = novo;
        }
        else{
            aux = *listaServ;
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

void imprimirF(NoF *no){
    
    printf("\n------ LISTA FUNCIONÁRIOS --------");
    while (no)
    {
        imprimirFuncionarios(no->funcionarios);
        printf("\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------");
}

void imprimirS(NoS *no){
    
    printf("\n------ LISTA SERVIÇOS --------");
    while (no)
    {
        imprimirServicos(no->servicos);
        printf("\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------");
}


int menuCliente(){
    int areaCliente;
    
    printf("\n---------- ÁREA CLIENTE ----------\n");
    printf("\n0 - Sair\n1 - Cadastrar Cliente\n2 - Listar Clientes\n");
    printf("\n----------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaCliente);
    return areaCliente;
}

int menuFuncionario(){
    
    int areaFunc;
    printf("\n-------- ÁREA FUNCIONÁRIO --------\n");
    printf("\n0 - Sair\n1 - Cadastrar Funcionário\n2 - Listar Funcionários\n");
    printf("\n------------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaFunc);
    return areaFunc;
}

int menuServico(){
    
    int areaServ;
    printf("\n-------- ÁREA SERVIÇOS --------\n");
    printf("\n0 - Sair\n1 - Cadastrar Serviços\n2 - Listar Serviços\n3 - Listar Serviços Prestados");
    printf("\n------------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaServ);
    return areaServ;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opcao, areaCliente, areaFuncionario, areaServico;
    No *listaCliente = NULL;
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


/*
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
//*/

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