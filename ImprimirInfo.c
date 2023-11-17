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