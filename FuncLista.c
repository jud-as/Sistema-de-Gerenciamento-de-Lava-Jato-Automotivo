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
    
    getchar();
    printf("\nCADASTRO CLIENTE\n");
    printf("\nNome: ");fgets(c.nome, 49, stdin);
    printf("\nData de nascimento: ");
    printf("\nDia: ");scanf("%d", &c.data.dia);
    printf("Mês: ");scanf("%d", &c.data.mes);
    printf("Ano: ");scanf("%d", &c.data.ano);
    printf("\nE-mail: ");scanf("%s", c.email);
    printf("Telefone: ");scanf("%ld", &c.telefone);
    printf("Endereço: ");
    getchar();
    printf("\nRua: ");fgets(c.endereco.rua, 29, stdin);
    printf("Número: ");scanf("%d", &c.endereco.numero);
    getchar();
    printf("Bairro: ");fgets(c.endereco.bairro, 29, stdin);
    printf("UF: ");scanf("%s", c.endereco.uf);
    printf("\n\nCADASTRO REALIZADO.");
    getchar();
    return c;
}

Funcionarios solicitarInfosFuncionarios(){
    clrscr();
    Funcionarios f;
    getchar();
    printf("\nCADASTRO FUNCIONÁRIO\n");
    printf("\nNome: ");fgets(f.nome,49,stdin);
    printf("\nData de nascimento: ");
    printf("\nDia: ");scanf("%d", &f.data.dia);
    printf("Mês: ");scanf("%d", &f.data.mes);
    printf("Ano: ");scanf("%d", &f.data.ano);
    getchar();
    printf("E-mail: ");fgets(f.email,49,stdin);
    printf("\nConta Bancária: ");
    printf("\nNúmero da Agência: ");scanf("%d", &f.contaBancaria.NumeroAgencia);
    printf("Número da Conta: ");scanf("%d", &f.contaBancaria.NumeroConta);
    printf("Digito de Verificação: ");scanf("%d", &f.contaBancaria.DigitoVerf);
    printf("\nTelefone: ");scanf("%ld", &f.telefone);
    printf("Endereço: ");
    getchar();
    printf("\nRua: ");fgets(f.endereco.rua,29,stdin);;
    printf("Número: ");scanf("%d", &f.endereco.numero);
    getchar();
    printf("Bairro: ");fgets(f.endereco.bairro,29,stdin);
    printf("UF: ");fgets(f.endereco.uf,29,stdin);
    getchar();
    printf("\n\nCADASTRO REALIZADO.");
    return f;
}

Servicos solicitarInfosServicos(){
    clrscr();
    Servicos s;
    getchar();
    printf("\nCADASTRO SERVIÇO:\n");
    printf("\nNome Serviço: "); fgets(s.nomeServico, 49, stdin); 
    printf("Descrição do Serviço: ");fgets(s.descricao, 99, stdin);
    printf("Valor do Serviço: ");scanf("%f", &s.valor);
    getchar();
    return s;
}

void imprimirClientes(Cliente c){
    printf("\nNome: %s", c.nome);
    printf("\nData de nascimento: %d/%d/%d", c.data.dia, c.data.mes,c.data.ano);
    printf("\nE-mail: %s", c.email);
    printf("\nTelefone: %ld", c.telefone);
    printf("\nEndereço:\nRua: %s\nNúmero: %d\nBairro: %s\nUF: %s", c.endereco.rua, c.endereco.numero, c.endereco.bairro, c.endereco.uf);
}

void imprimirFuncionarios(Funcionarios f){
    printf("\nNome: %s", f.nome);
    printf("\nData de nascimento: %d/%d/%d", f.data.dia, f.data.mes,f.data.ano);
    printf("\nE-mail: %s", f.email);
    printf("\nConta Bancária:\nNumero da Agência: %d\nNumero da Conta: %d\nDigito de Verificação: %d\n", f.contaBancaria.NumeroAgencia, f.contaBancaria.NumeroConta, f.contaBancaria.DigitoVerf);
    printf("\nTelefone: %ld", f.telefone);
    printf("\nEndereço:\nRua: %sNúmero: %d\nBairro: %sUF: %s", f.endereco.rua, f.endereco.numero, f.endereco.bairro, f.endereco.uf);
}

void imprimirServicos(Servicos s){
    printf("\nNome: %s", s.nomeServico);
    printf("Descrição: %s", s.descricao);
    printf("Valor: %.2f", s.valor);
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