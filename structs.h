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

typedef struct funcionarios{
    char nome[50];
    Data data;
    char email[50];
    int contaBancaria;
    long int telefone;
    Endereco endereco;
}Funcionarios;