#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
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
    printf("CPF: ");scanf("%ld",&c.cpf);
    printf("\nData de nascimento: ");
    printf("\nDia: ");scanf("%d", &c.data.dia);
    printf("Mês: ");scanf("%d", &c.data.mes);
    printf("Ano: ");scanf("%d", &c.data.ano);
    printf("\nE-mail: ");scanf("%s", c.email);
    printf("Telefone: ");scanf("%ld", &c.telefone);
    printf("\nEndereço: ");
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
    printf("CPF: ");scanf("%ld",&f.cpf);
    printf("\nData de nascimento: ");
    printf("\nDia: ");scanf("%d", &f.data.dia);
    printf("Mês: ");scanf("%d", &f.data.mes);
    printf("Ano: ");scanf("%d", &f.data.ano);
    getchar();
    printf("E-mail: ");fgets(f.email,49,stdin);
    printf("\nCargo Atribuido: ");fgets(f.cargo,19,stdin);
    printf("\nConta Bancária: ");
    printf("\nNúmero da Agência: ");scanf("%d", &f.contaBancaria.NumeroAgencia);
    printf("Número da Conta: ");scanf("%d", &f.contaBancaria.NumeroConta);
    printf("Digito de Verificação: ");scanf("%d", &f.contaBancaria.DigitoVerf);
    printf("\nTelefone: ");scanf("%ld", &f.telefone);
    printf("\nEndereço: ");
    getchar();
    printf("\nRua: ");fgets(f.endereco.rua,29,stdin);;
    printf("Número: ");scanf("%d", &f.endereco.numero);
    getchar();
    printf("Bairro: ");fgets(f.endereco.bairro,29,stdin);
    printf("UF: ");fgets(f.endereco.uf,3,stdin);
   
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

ServicoPrestado solicitarInfosServicosPrestados(){
    clrscr();
    ServicoPrestado sp; 
    
    printf("\nCADASTRO SERVIÇO PRESTADO:\n");
    printf("CÓDIGO FUNCIONÁRIO: ");scanf("%d", &sp.funcionarioPrestador.codFuncionario);   
    printf("CÓDIGO SERVICO: ");scanf("%d", &sp.servicoPrestado.codServico);
    printf("CPF CLIENTE ATENDIDO: ");scanf("%ld", &sp.clienteAtendido.cpf);
    getchar();
    printf("\nLOCAL DE ATENDIMENTO (UF): ");scanf("%s", sp.uf);
    printf("\nData do atendimento: ");
    printf("\nDia: ");scanf("%d", &sp.dataServico.dia);
    printf("Mês: ");scanf("%d", &sp.dataServico.mes);
    printf("Ano: ");scanf("%d", &sp.dataServico.ano);
    getchar();
    printf("\nObservações do serviço: ");fgets(sp.detalhamentoServico, 100, stdin);
    return sp;     
}

void imprimirServicosPrestados(ServicoPrestado sp){

    printf("\nCÓDIGO FUNCIONÁRIO: %d", sp.funcionarioPrestador.codFuncionario);
    printf("\nNOME DO FUNCIONÁRIO: %s",sp.funcionarioPrestador.nome);
    printf("\nCÓDIGO DO SERVIÇO: %d",sp.servicoPrestado.codServico);
    printf("\nTIPO DO SERVIÇO: %s",sp.servicoPrestado.nomeServico);
    printf("\nCPF CLIENTE: %ld",sp.clienteAtendido.cpf);
    printf("\nNOME DO CLIENTE: %s",sp.clienteAtendido.nome);
    printf("\nDATA: %d/%d/%d", sp.dataServico.dia,  sp.dataServico.mes, sp.dataServico.ano);
    printf("\nDESCRIÇÃO: %s", sp.detalhamentoServico);
    printf("\nLOCAL DE ATENDIMENTO: %s", sp.servicoPrestado.uf);
}

void imprimirClientes(Cliente c){
    printf("\nNome: %s", c.nome);
    printf("\nCPF: %ld", c.cpf);
    printf("\nData de nascimento: %d/%d/%d", c.data.dia, c.data.mes,c.data.ano);
    printf("\nE-mail: %s", c.email);
    printf("\nTelefone: %ld", c.telefone);
    printf("\nEndereço:\nRua: %sNúmero: %d\nBairro: %sUF: %s", c.endereco.rua, c.endereco.numero, c.endereco.bairro, c.endereco.uf);
}

void imprimirFuncionarios(Funcionarios f){
    printf("\nCÓDIGO: %d", f.codFuncionario);
    printf("\nNome: %s", f.nome);
    printf("CPF: %ld", f.cpf);
    printf("\nData de nascimento: %d/%d/%d", f.data.dia, f.data.mes,f.data.ano);
    printf("\nConta Bancária:\nNumero da Agência: %d\nNumero da Conta: %d\nDigito de Verificação: %d\n", f.contaBancaria.NumeroAgencia, f.contaBancaria.NumeroConta, f.contaBancaria.DigitoVerf);
    printf("\nTelefone: %ld", f.telefone);
    printf("\nE-mail: %s", f.email);
    printf("\nEndereço:\nRua: %sNúmero: %d\nBairro: %sUF: %s", f.endereco.rua, f.endereco.numero, f.endereco.bairro, f.endereco.uf);
}

void imprimirServicos(Servicos s){
    printf("\nCÓDIGO: %d", s.codServico);
    printf("\nNome: %s", s.nomeServico);
    printf("Descrição: %s", s.descricao);
    printf("Valor: %.2f\n", s.valor);
}


No* buscaCliente(No **listaClientes, char *buscaUF){
    No *aux, *no = NULL;
    aux = *listaClientes;
    while (aux)
    {
        if(strcmp(buscaUF, aux->cliente.endereco.uf) == 0){
            printf("\n");
            imprimirClientes(aux->cliente);
        }
        aux = aux->proximo;
    }

    return no;
}

    NoSp* buscaFuncTipo(NoSp **listaServPrest, int codServico){
    NoSp *aux, *no = NULL;
    aux = *listaServPrest;
    while (aux)
    {
        if(codServico == aux->servicoPrestrado.servicoPrestado.codServico){
            printf("\n\n");
            imprimirFuncionarios(aux->servicoPrestrado.funcionarioPrestador);
        }
        aux = aux->proximo;
    }

    return no;
}

Funcionarios *buscaFuncionario(NoF **listaFuncionarios, int *buscaCodigo){
    NoF *aux;
    aux = *listaFuncionarios;
    while (aux && *buscaCodigo != aux->funcionarios.codFuncionario){
        aux = aux->proximo;
    }
    if (aux)
    {
        return &(aux->funcionarios);
    } else{
        return NULL;
    }
}

Cliente *buscaClienteCpf(No **listaClientes, int *buscaCodigo){
    No *aux;
    aux = *listaClientes;
    while (aux && *buscaCodigo != aux->cliente.cpf){
        aux = aux->proximo;
    }
    if (aux)
    {
        return &(aux->cliente);
    } else{
        return NULL;
    }
}

Servicos *buscaServicoCod(NoS **listaServico, int *buscaCodigo){
    NoS *aux;
    aux = *listaServico;
    while(aux && *buscaCodigo != aux->servicos.codServico){
        aux = aux->proximo;
    }
    if(aux)
    {
        return &(aux->servicos);
    } else{
        return NULL;
    }
}


void inserir_no_fim(No **listaClientes, Cliente cliente){
    No *aux, *novo = malloc(sizeof(No));
    int i;


    for(i=0; i < strlen(cliente.nome); i++){
   			
   		if(cliente.nome[0]>='a')
         {
            cliente.nome[0]-=32;

        }
        if(cliente.nome[i] == 32)
        {

            cliente.nome[i+1]-=32;

        }
    }


    if (novo){
        novo->cliente = cliente;
        novo->proximo = NULL;

        //é o primeiro?
        if (*listaClientes == NULL || strcmp(cliente.nome, (*listaClientes)->cliente.nome) < 0){
            novo->proximo = *listaClientes;
            *listaClientes = novo;
        }
        else{
            aux = *listaClientes;
            while (aux->proximo && strcmp(cliente.nome, aux->proximo->cliente.nome) >=0 )
            {
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo; 
        }
    }
    else
        printf("Erro ao alocar memória.");

}

void inserir_no_fim_func(NoF **listaFunc, Funcionarios funcionarios){
    NoF *aux, *novo = malloc(sizeof(NoF));
     int i;
    
    
     for(i=0; i < strlen(funcionarios.nome); i++){
   			
   		if(funcionarios.nome[0]>='a')
         {
            funcionarios.nome[0]-=32;

        }
        if(funcionarios.nome[i] == 32)
        {

           funcionarios.nome[i+1]-=32;

        }
    }


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
    
    int i;
    
    
    for(i=0; i < strlen(servicos.nomeServico); i++){
   			
   		if(servicos.nomeServico[0]>='a')
         {
            servicos.nomeServico[0]-=32;

        }
        if(servicos.nomeServico[i] == 32)
        {

           servicos.nomeServico[i+1]-=32;

        }
    }


    if (novo)
    {
        novo->servicos = servicos;
        novo->proximo = NULL;
        

        if (*listaServ == NULL || servicos.valor < (*listaServ)->servicos.valor)
        {
            novo->proximo = *listaServ;
            *listaServ = novo;
            
        }
        else{
            aux = *listaServ;
            while (aux->proximo && servicos.valor >= aux->proximo->servicos.valor)
            {
                aux = aux->proximo;
            }
            
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            
        } 

    }
    else
        printf("Erro ao alocar memória."); 
}

void inserir_servicos_prestados(NoSp **listaServPrest, ServicoPrestado servicoPrestado){
    NoSp *novo = malloc(sizeof(NoSp));

    if (novo)
    {
        novo->servicoPrestrado = servicoPrestado;
        novo->proximo = *listaServPrest;
        *listaServPrest = novo;
    }
    else{
        printf("Erro ao alocar memória.\n");
    }
    
}


void imprimir(No *no){
    
    printf("\n-------- LISTA CLIENTES ----------\n");
    while (no)
    {
        imprimirClientes(no->cliente);
        printf("\n\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------\n");
}

void imprimirF(NoF *no){
    
    printf("\n------ LISTA FUNCIONÁRIOS --------\n");
    while (no)
    {
        imprimirFuncionarios(no->funcionarios);
        printf("\n\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------\n");
}

void imprimirS(NoS *no){
    
    printf("\n------ LISTA SERVIÇOS --------\n");
    while (no)
    {
        imprimirServicos(no->servicos);
        printf("\n\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------\n");
}

void imprimirSp(NoSp *no){
    
    printf("\n------ LISTA SERVIÇOS PRESTADOS --------\n");
    while (no)
    {
        imprimirServicosPrestados(no->servicoPrestrado);
        printf("\n\n");
        no = no->proximo;    
    }
    printf("\n\n----------- FIM LISTA ------------");
}

int menuCliente(){
    int areaCliente;
    
    printf("\n---------- ÁREA CLIENTE ----------\n");
    printf("\n0 - Sair\n1 - Cadastrar Cliente\n2 - Listar Clientes\n3 - Buscar por Estado");
    printf("\n----------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaCliente);
    return areaCliente;
}

int menuFuncionario(){
    
    int areaFunc;
    printf("\n-------- ÁREA FUNCIONÁRIO --------\n");
    printf("\n0 - Sair\n1 - Cadastrar Funcionário\n2 - Listar Funcionários\n3 - Buscar por Cargo");
    printf("\n------------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaFunc);
    return areaFunc;
}

int menuServico(){
    
    int areaServ;
    printf("\n-------- ÁREA SERVIÇOS --------\n");
    printf("\n0 - Sair\n1 - Cadastrar Serviços\n2 - Listar Serviços\n3 - Cadastrar Serviços Prestados\n4 - Listar Serviços Prestados");
    printf("\n------------------------------------\n");
    printf("OPÇÃO: "); scanf("%d", &areaServ);
    return areaServ; 
}

int codRegistro(){

    srand(time(NULL));

    int x = rand()%100;
    x = x + 1;
    return x;
}