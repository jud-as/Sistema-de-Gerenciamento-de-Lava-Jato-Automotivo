#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashS.h"



void insert(struct HashTable* hashtable, int key, Servicos serv){
	
	int index = hash(key);
	
	struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
	newNode->key = key; 
	strncpy(newNode->serv.nomeServico, serv.nomeServico, sizeof(newNode->serv.nomeServico));
	newNode->next = NULL; 


	if (hashtable->array[index] == NULL){
		
		hashtable->array[index] = newNode;
	}else{
		
		struct HashNode* current = hashtable->array[index];
		
		while(current->next != NULL){
		
			current = current->next;	
			
		}
		current->next = newNode;
	}
	
}

char* get(struct HashTable* hashtable, int key) {
	
	int index = hash(key);
	struct HashNode* current = hashtable->array[index];
	while (current != NULL){
		
		if(current->key == key){
		return current->serv.nomeServico;
		}
		current = current->next;
	}
	
	return NULL;
}

Servicos cadastroServico(struct HashTable* hashtable) {
    int key = 1, op = 1;
    Servicos serv;
  
	 getchar(); 
    while (op != 0) {

    printf("\nCADASTRO SERVIÇO:\n");
    printf("\nNome Serviço: ");fgets(serv.nomeServico,50, stdin);
    printf("\nDescrição do Serviço: ");fgets(serv.descricao,100, stdin);
    printf("\nValor do Serviço: ");scanf("%f", &serv.valor);

    insert(hashtable, key, serv);

    key++;

    printf("\n\nCADASTRO REALIZADO.");

    printf("\n\nDeseja inserir outro aluno?\n");
    printf("Não = 0       SIM = 1\n");scanf("%d", &op);
   
     getchar(); 

    }

    return serv;

}

Servicos consultarServico(struct HashTable* hashtable) {

int key, op = 1;


    while (op != 0) {
    printf("Insira o código do serviço desejado: \n");
    scanf("%d", &key);
    getchar(); 
    int* key = get(hashtable, key);

    	if (key != NULL) {
        printf("\nNome: %s", serv.nomeServico);
        printf("\nDescrição: %s", serv.descricao);
        printf("Valor: %.2f", serv.valor);
   	 	}else {
        printf("Serviço não encontrado no catálogo.\n");
    	}
    	
     	printf("\n\nDeseja buscar outro serviço?\n");
        printf("Não = 0       SIM = 1\n");
        scanf("%d", &op);
        
        system("cls");
	}  

}
/*
Servicos solicitarInfosServicos(){
    clrscr();
    Servicos s;

    printf("\nCADASTRO SERVIÇO:\n");
    printf("\nNome Serviço: ");scanf("%s", &s.nomeServico);
    printf("\nDescrição do Serviço: ");scanf("%s", &s.descricao);
    printf("\nValor do Serviço: ");scanf("%f", &s.valor);

}*/