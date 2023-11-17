
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

typedef struct endereco{
    int cep;
    char rua[30];
    int numero;    
    char bairro[30];
    char uf[3];
}Endereco;

typedef struct cliente{
    char nome[50];
    long int cpf;
    Data data;
    char email[50];
    long int telefone;
    Endereco endereco;

}Cliente;

typedef struct funcionarios{
    int codFuncionario;
    char nome[50];
    char cargo[20];
    long int cpf;
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
    char uf[3];
    float valor;
}Servicos;

typedef struct servicoPrestado{
    Servicos servicoPrestado;
    Funcionarios funcionarioPrestador;
    Cliente clienteAtendido;
    Data dataServico;
    char uf[3];
    char detalhamentoServico[100];
}ServicoPrestado;

typedef struct no{
    Cliente cliente;
    struct no *proximo;
}No;

typedef struct nof{
    Funcionarios funcionarios;
    struct nof *proximo;
}NoF;

typedef struct nos{
    Servicos servicos;
    struct nos *proximo;
}NoS;

typedef struct nosp{
    ServicoPrestado servicoPrestrado;
    struct nosp *proximo;
}NoSp;
