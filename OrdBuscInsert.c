#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include "structs.h"
#include "SolicitarInfo.c"
#include "ImprimirInfo.c"






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


float calculoPreco(float gastoMensal){ 
    float valor;
    valor = ((gastoMensal/30)*1.60);
    return valor;
}

int codRegistro(){

    srand(time(NULL));

    int x = rand()%100;
    x = x + 1;
    return x;
}