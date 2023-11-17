


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
    printf("\nLOCAL DE ATENDIMENTO (UF): ");fgets(sp.servicoPrestado.uf,3,stdin);
    printf("\nData do atendimento: ");
    printf("\nDia: ");scanf("%d", &sp.dataServico.dia);
    printf("Mês: ");scanf("%d", &sp.dataServico.mes);
    printf("Ano: ");scanf("%d", &sp.dataServico.ano);
    getchar();
    printf("\nObservações do serviço: ");fgets(sp.detalhamentoServico, 100, stdin);
    return sp;     
}