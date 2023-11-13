
typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct contaBancaria{

int NumeroAgencia;
int NumeroConta;
int DigitoVerf;

}ContaBancaria;

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
    long int telefone;
    Endereco endereco;
    ContaBancaria contaBancaria;
}Funcionarios;

typedef struct servicos{
    int codServico;
    char nomeServico[50];
    char descricao[100];
    float valor;
}Servicos;

typedef struct servicoPrestado{
    Servicos servicoPrestado;
    Funcionarios funcionarioPrestador;
    Cliente clienteAtendido;
    Data dataServico;
    char detalhamentoServico[100];
}ServicoPrestado;

typedef struct no {
    Cliente cliente;
    struct no *proximo;
}No;

typedef struct nof {
    Funcionarios funcionarios;
    struct no *proximo;
}NoF;

typedef struct nos{
    Servicos servicos;
    struct no *proximo;
}NoS;