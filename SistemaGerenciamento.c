#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct servicos{
    char descricao[100];
    int tipo;

}Servicos;

typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct endereco {
    int cep;
    int rua;
    int numero;    
    char bairro[30];
    char uf[30];        
}Endereco;

typedef struct cliente{
    char nome[50];
    Data data;
    char email[50];
    long int telefone;
    Endereco endereco;
}Cliente;


Cliente solicitarInfosCliente() {

    Cliente c;
    int opc = 1;
    
    
    printf("\n-------------Cadastro Cliente -------------\n");
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
    printf("\n\nSair - 0\nContinuar - 1\n");
    printf("\nOPÇÃO: "); 
    scanf("%d", &opc);

    return c;
}



void imprimirClientes(Cliente c) {
    printf("\nNome: %s", c.nome);
    printf("\nData de nascimento: %d/%d/%d", c.data.dia, c.data.mes,c.data.ano);
    printf("\nE-mail: %s", c.email);
    printf("\nTelefone: %ld", c.telefone);
    printf("\nEndereço:\nRua: %d\nNúmero: %d\nBairro: %s\nUF: %s", c.endereco.rua, c.endereco.numero, c.endereco.bairro, c.endereco.uf);
}




int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opcao;
    Cliente c;
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
            c = solicitarInfosCliente();
            break;

        case 2:
        
            break;

        default:
            imprimirClientes(c);
            break;
        }

    } while (opcao != 0);

   
    return 0;
}