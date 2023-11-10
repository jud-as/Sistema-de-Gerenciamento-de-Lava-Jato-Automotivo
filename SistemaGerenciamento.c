#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct servicos{
    char descricao[100];
    int tipo;

}Servicos;

typedef struct data {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct endereco {
    int rua;
    int numero;    
    char bairro[30];
    char uf[30];        
}Endereco;

typedef struct cliente{
    char nome[50];
    Data data[10];
    char email[50];
    int telefone[30];
    Endereco endereco [10];
}Cliente;


Cliente solicitarInfosCliente() {

    Cliente c;
    int opc = 1;
    int i = 0;

    do
    {
        printf("\n-------------Cadastro Cliente -------------\n");
        printf("\nNome: ");scanf("%s", &c.nome[i]);
        printf("\nData de nascimento: ");
        printf("\nDia: ");scanf("%d", &c.data[i].dia);
        printf("Mês: ");scanf("%d", &c.data[i].mes);
        printf("Ano: ");scanf("%d", &c.data[i].ano);
        printf("\nE-mail: ");scanf("%s", &c.email[i]);
        printf("Telefone: ");scanf("%d", &c.telefone[i]);
        printf("Endereço: ");
        printf("\nRua: ");scanf("%d", &c.endereco[i].rua);
        printf("Número: ");scanf("%d", &c.endereco[i].numero);
        printf("Bairro: ");scanf("%s", &c.endereco[i].bairro);
        printf("UF: ");scanf("%s", &c.endereco[i].uf);
        printf("\n\nSair - 0\nContinuar - 1\n");
        printf("\nOPÇÃO: "); 
        scanf("%d", &opc);
        i++;
    } while (opc != 0);

    return c;
}



void imprimirClientes(Cliente c) {
    printf("\nNome: %s", c.nome);
    printf("\nData de nascimento: %d/%d/%d", c.data->dia, c.data->mes,c.data->ano);
    printf("\nE-mail: %s", c.email);
    printf("\nTelefone: %d", c.telefone);
    printf("\nEndereço:\nRua: %d\nNúmero: %d\nBairro: %s\nUF: %s", c.endereco->rua, c.endereco->numero, c.endereco->bairro, c.endereco->uf);

}




int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opcao;
    
    do
    {
        printf("\n0 - Sair\n1 - Área Clientes\n2 - Área Funcionários\n3 - Área Serviços");
        printf("\n\nOPÇÃO: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {

        case 0:

            break;
            
        case 1:
            solicitarInfosCliente();
            break;

        case 2:
        
            break;

        default:
        printf("Operação inexistente.");
            break;
        }

    } while (opcao != 0);

   
    return 0;
}