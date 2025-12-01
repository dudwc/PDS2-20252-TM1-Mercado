#include "../include/Sistema.hpp"
#include <cstdlib>  // Para std::exit
#include <fstream>
#include <sstream>
#include <iomanip>
//============================= Sistema ============================//

Sistema::Sistema() {}

Sistema::~Sistema() {}

void Sistema::print(std::string texto) {
    int delay_milliseconds = 1; // tempo de atraso entre cada caractere

    for (char c : texto) {
        std::cout << c << std::flush; // imprime caractere e limpa o buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_milliseconds)); // funcao de atraso
    }
}

void Sistema::carregar() {
    int delay_milliseconds = 30; // tempo de atraso entre cada caractere

    print("CARREGANDO");
    for (char c : "...................................\n") {
        std::cout << c << std::flush; // imprime caractere e limpa o buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_milliseconds)); // funcao de atraso
    }
}

void Sistema::iniciar(){
    int c;
   while(true) {
        system("cls");
        print("1. Iniciar sistema\n2. Sair\nEscolha uma opcao: ");
        std::cin >> c;
        system("cls");
        switch(c){
            case 1:{
                exibirMenu();
                break;}
                
            case 2:
                print("Saindo do sistema...\n");
                std::exit(0);
            
            default:
                print("Opcao invalida. Tente novamente.\n");
                break;
        }
            
        };
}

void Sistema::exibirLogo(){
    std::ifstream entrada("arquivos/mercado.txt");
            if (!entrada.is_open()) {
                print("Erro ao abrir o arquivo de logo.\n");
                std::exit(1);
            }

            std::string linha;
            while (std::getline(entrada, linha)) {
                std::cout << linha << '\n';
            }
            entrada.close();
}

void Sistema::exibirMenu(){
    int opcao;
    SistemaFuncionario sistemaF;
    SistemaCliente sistemaC;
    while(true) {
        system("cls");
        exibirLogo();
        print("\n--- Menu Principal ---\n");
        print("1. Comprar\n");
        print("2. Entrar como funcionario\n");
        print("3. Sair\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                system("cls");
                sistemaC.iniciar();
                break;
            case 2:
                system("cls");
                sistemaF.iniciar();
                break;
            case 3:
                system("cls");
                print("Saindo do sistema...\n");
                std::exit(0);
            default:
                system("cls");
                print("Opcao invalida. Tente novamente.\n");
                break;
        }
    };
}

void Sistema::menuEstoque() {}

//============================= SistemaFuncionario ============================//

int SistemaFuncionario::proximoIDFuncionario = 3974;

SistemaFuncionario::SistemaFuncionario() {
    carregarProximoID();
    std::ifstream arquivoFuncionarios("arquivos/funcionarios.txt");
    if (!arquivoFuncionarios.is_open()) {
        print("Erro ao iniciar sistema.\n");
        std::exit(1);
    }
    std::string linha;
    while(std::getline(arquivoFuncionarios, linha)) {
        std::istringstream iss(linha);
        std::string nome;
        int id;
        std::string senha;

        if(!(iss >> nome >> id >> senha)) {
            print("Formato de arquivo invalido para funcionario: " + linha + "\n");
            continue;
        } else {
            Funcionario funcionario(nome, id, senha);
            funcionarios.push_back(funcionario);
        }
    }
    arquivoFuncionarios.close();
}

SistemaFuncionario::~SistemaFuncionario() {}

void SistemaFuncionario::iniciar() {
    int opcao;
    while(true) {
        system("cls");
        print("1. Fazer login.\n");
        print("2. Voltar ao menu principal.\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                system("cls");
                loginFuncionario();
                return;
            case 2:
                return;
            default:
                system("cls");
                print("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
}

void SistemaFuncionario::exibirMenu() {
    int opcao;
    while(true) {
        system("cls");
        print("--- Menu de Funcionario ---\n");
        print("1. Gerenciar Estoque\n");
        print("2. Cadastrar novo funcionario\n");
        print("3. Sair\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                system("cls");
                menuEstoque();
                break;
            case 2:
                system("cls");
                cadastrarFuncionario();
                break;
            case 3:
                system("cls");
                print("Saindo do sistema...\n");
                carregar();
                return;
            default:
                system("cls");
                print("Opcao invalida. Tente novamente.\n");
                break;
        }

    }
}

void SistemaFuncionario::menuEstoque() {
    int opcao;
    while(true) {
        system("cls");
        print("--- Menu de Estoque ---\n");
        print("1. Listar produtos\n");
        print("2. Adicionar produto\n");
        print("3. Remover produto\n");
        print("4. Voltar\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                system("cls");
                estoque.listarProdutos();
                print("Pressione ENTER para voltar.");
                std::cin.ignore();
                std::cin.get();
                break;
            case 2:{
                std::string nome, unidade;
                double preco, quantidade;
                int id;

                system("cls");
                print("Adicionar novo produto ao estoque\n");
                print("Nome: ");
                std::cin >> nome;
                print("Preco: ");
                std::cin >> preco;
                print("Unidade de medida (U para unidade, KG para quilo): ");
                std::cin >> unidade;
                print("Quantidade: ");
                std::cin >> quantidade;

                int maiorID = 0;
                for (const auto& par : estoque.getProdutos()) {
                    if (par.first->getID() > maiorID) {
                        maiorID = par.first->getID();
                    }
                }
                id = maiorID + 1;

                if (unidade == "KG") {
                    FrutasEVerduras* produto = new FrutasEVerduras(nome, preco, id);
                    estoque.adicionarProduto(produto, quantidade);
                } else {
                    Produto* produto = new Produto(nome, preco, id, unidade);
                    estoque.adicionarProduto(produto, quantidade);
                }

                print("Produto adicionado com sucesso!\n");
                print("Pressione ENTER para continuar.");
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 3:{
                    system("cls");
                    estoque.listarProdutos();
                    int id;
                    double quantidade;
                    print("Digite o ID do produto a ser removido: ");
                    std::cin >> id;
                    print("Digite a quantidade a ser removida: ");
                    std::cin >> quantidade;
                    estoque.removerProduto(id, quantidade);
                    print("Pressione ENTER para continuar.");
                    std::cin.ignore();
                    std::cin.get();
                }
                break;
            case 4:
                return;
            default:
                system("cls");
                print("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
}

void SistemaFuncionario::carregarProximoID() {
    std::ifstream arquivo("arquivos/proximoID.txt");
    if (arquivo.is_open()) {
        arquivo >> proximoIDFuncionario;
        arquivo.close();
    }
}

void SistemaFuncionario::salvarProximoID() {
    std::ofstream arquivo("arquivos/proximoID.txt");
    if (arquivo.is_open()) {
        arquivo << proximoIDFuncionario;
        arquivo.close();
    }
}

Funcionario* SistemaFuncionario::cadastrarFuncionario(){
    std::string nome, senha;
    int id = proximoIDFuncionario;
    
    print("Digite o nome do funcionario: ");
    std::cin >> nome;
    
    print("Digite a senha do funcionario: ");
    std::cin >> senha;
    
    Funcionario novoFuncionario(nome, id, senha);
    funcionarios.push_back(novoFuncionario);
    
    arquivo.open("arquivos/funcionarios.txt", std::ios::out | std::ios::trunc);
    if(!arquivo.is_open()){
        print("Erro ao abrir o arquivo de funcionarios para escrita.\n");
        return nullptr;
    }
    for(const auto& funcionario : funcionarios){
        arquivo << funcionario.getNome() << " "
        << funcionario.getID() << " "
        << funcionario.getSenha()
        << std::endl;
    }
    
    proximoIDFuncionario++;
    salvarProximoID();
    
    print("Funcionario cadastrado com sucesso! ID: " + std::to_string(id) + "\n");
    print("Pressione ENTER para continuar.");
    std::cin.ignore();
    std::cin.get();
    
    return &funcionarios.back();
}

void SistemaFuncionario::loginFuncionario(){
    int id;
    std::string senha;
    print("ID: ");
    std::cin >> id;
    print("Senha: ");
    std::cin >> senha;
    bool status = verificarLogin(id, senha);
    if(status){
        for(auto& funcionario : funcionarios){
            if(funcionario.getID() == id && funcionario.getSenha() == senha){
                funcionario.setLogado(true);
                exibirMenu();
            }
        }
    }
}

bool SistemaFuncionario::verificarLogin(const int id, const std::string& senha){
    for(const auto& funcionario : funcionarios){
        if(funcionario.getID() == id && funcionario.getSenha() == senha){
            system("cls");
            print("Login bem sucedido! Bem-vinda(o), " + funcionario.getNome() + ".\n");
            carregar();
            return true;
        }
    }
    print("Falha no login. Verifique suas credenciais.\n");
    return false;
}

//============================= SistemaCliente ============================//

SistemaCliente::SistemaCliente() : clienteLogado(nullptr){
    std::ifstream arquivoClientes("arquivos/clientes.txt");
    if (!arquivoClientes.is_open()) return;

    std::string linha, cpf, nome;
    while (std::getline(arquivoClientes, linha)) {
        if (linha.empty()) continue;
        
        std::istringstream iss(linha);
        if(iss >> cpf >> std::ws) {
            std::getline(iss, nome);
            if(!nome.empty()) {
                clientes.emplace_back(nome, cpf);
            }
        }
    }
    arquivoClientes.close();
}

SistemaCliente::~SistemaCliente() {
    std::ofstream arquivoSaida("arquivos/clientes.txt", std::ios::trunc);
    if (arquivoSaida.is_open()) {
        for (auto& c : clientes) {
            arquivoSaida << c.getCPF() << " " << c.getNome() << "\n";
        }
        arquivoSaida.close();
    }
}


void SistemaCliente::iniciar() {
    int opcao;
    while(true) {
        system("cls");
        print("---- Menu do Cliente ----\n");
        print("1. Fazer login\n");
        print("2. Fazer cadastro\n");
        print("3. Voltar ao menu principal\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                system("cls");
                loginCliente();
                break;
            case 2:
                system("cls");
                cadastrarCliente();
                break;
            case 3:
                clienteLogado = nullptr;
                return;
            default:
                system("cls");
                print("Opcao invalida.\n");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}

void SistemaCliente::exibirMenu() {
    if(clienteLogado == nullptr) return;

    int opcao;
    while(clienteLogado != nullptr) {
        system("cls");
        print("--- Menu do Cliente: " + clienteLogado->getNome() + " ---\n");
        print("1. Fazer compras\n");
        print("2. Ver historico de compras\n");
        print("3. Sair (Logout)\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:{
                system("cls");
                Caixa caixa(estoque); 

                int op = 0;
                while(op != 5){
                    system("cls");
                    print("--- Carrinho de Compras ---\n");
                    print("1. Adicionar item\n");
                    print("2. Remover item\n");
                    print("3. Exibir carrinho\n");
                    print("4. Finalizar compra\n");
                    print("5. Voltar ao menu anterior\n");
                    print("Escolha uma opcao: ");
                    std::cin >> op;

                    switch(op){
                        case 1: {
                            std::string nome;
                            double qtd;
                            estoque.listarProdutos();
                            print("Digite o nome do produto: ");
                            std::cin.ignore(); 
                            std::getline(std::cin, nome);
                            
                            print("Digite a quantidade: ");
                            std::cin >> qtd;
                            
                            caixa.adicionarItem(nome, qtd);
                            
                            print("Pressione ENTER...");
                            std::cin.ignore();
                            std::cin.get();
                            break;
                        }
                        case 2: {
                            std::string nome;
                            double qtd;
                            print("Digite o nome do produto para remover: ");
                            std::cin.ignore();
                            std::getline(std::cin, nome);
                            
                            print("Digite a quantidade: ");
                            std::cin >> qtd;
                            
                            caixa.removerItem(nome, qtd);
                            
                            print("Pressione ENTER...");
                            std::cin.ignore();
                            std::cin.get();
                            break;
                        }
                        case 3: {
                            caixa.exibirCarrinho();
                            double total = caixa.exibirTotal();
                            std::cout << std::fixed << std::setprecision(2);
                            std::cout << "Total parcial: R$ " << total << std::endl;
                            print("Pressione ENTER...");
                            std::cin.ignore();
                            std::cin.get();
                            break;
                        }
                        case 4: {
                            std::string formaPagamento;
                            double totalCompra = caixa.exibirTotal();
                            
                            print("Forma de pagamento (dinheiro/cartao/pix): ");
                            std::cin.ignore();
                            std::getline(std::cin, formaPagamento);

                            if(formaPagamento == "dinheiro" || formaPagamento == "Dinheiro") {
                                double valorPago;
                                print("Digite o valor a pagar: ");
                                std::cin >> valorPago;
                                caixa.finalizarCompra(formaPagamento, valorPago);
                            } else {
                                caixa.finalizarCompra(formaPagamento);
                            }
                            
                            if (totalCompra > 0) {
                                std::ofstream historico("arquivos/historico.txt", std::ios::app);
                                if(historico.is_open()) {
                                    historico << clienteLogado->getCPF() << " comprou R$ " 
                                              << std::fixed << std::setprecision(2) << totalCompra 
                                              << " via " << formaPagamento << "\n";
                                    historico.close();
                                }
                            }

                            print("Pressione ENTER para continuar...");
                            std::cin.ignore();
                            std::cin.get();
                            
                            op = 5; 
                            break;
                        }
                        case 5: 
                            print("Voltando ao menu anterior...\n");
                            break;
                        default:
                            print("Opcao invalida.\n");
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                    }
                }
                break;
            }
            case 2:
                system("cls");
                print("---- Historico de Compras ---- \n");
                {
                    std::ifstream historico("arquivos/historico.txt");
                    if(!historico.is_open()) {
                        print("Sem historico... \n");
                    } else {
                        std::string linha;
                        bool achou = false;
                        while (std::getline(historico, linha)) {
                            if (linha.find(clienteLogado->getCPF()) != std::string::npos) {
                                print(linha + "\n");
                                achou = true;
                            }
                        }
                        if(!achou) print("Nenhuma compra encontrada para voce.\n");
                        historico.close();
                    }
                }
                print("\nPressione ENTER para voltar. ");
                std::cin.ignore();
                std::cin.get();
                break;
            case 3:
                system("cls");
                print("Saindo...\n");
                clienteLogado = nullptr;
                carregar();
                return;
            default:
                system("cls");
                print("Opcao invalida. \n");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}

void SistemaCliente::menuEstoque() {
    
}

Cliente* SistemaCliente::cadastrarCliente() {
    std::string nome, cpf;

    print("----- Cadastro de Cliente -----\n");
    print("Digite o nome: ");
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nome);

    print("Digite o CPF: ");
    std::cin >> cpf;

    if (verificarLogin(cpf)) { 
        print("Ja existe um cliente com esse CPF! \n");
        print("Pressione ENTER...");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin.get();
        return nullptr;
    }

    std::ofstream arquivoSaida("arquivos/clientes.txt", std::ios::trunc); //bloco adcionado para corrigir a leitura do arquivo de clientes
    if (arquivoSaida.is_open()) {
        for (auto& c : clientes) {
            arquivoSaida << c.getCPF() << " " << c.getNome() << "\n";
        }
        arquivoSaida.close();
    }

    clientes.emplace_back(nome, cpf); //adiciona na memória RAM

    {
        std::ofstream arquivoSaida("arquivos/clientes.txt", std::ios::app);
        if (arquivoSaida.is_open()) {
            arquivoSaida << cpf << " " << nome << "\n";
            arquivoSaida.close();
        } else {
            print("Erro ao abrir clientes.txt para escrita. Cliente cadastrado apenas em memoria.\n");
        }
    } 

    return &clientes.back();
}

bool SistemaCliente::verificarLogin(const std::string& cpf) {
    for (auto& c : clientes) {
        if (c.getCPF() == cpf) return true;
    }
    return false;
}

void SistemaCliente::loginCliente(){
    std::string cpf;
    print("---- Login do Cliente ----\n");
    print("Digite seu CPF: ");
    std:: cin >> cpf;

    for (auto& c : clientes) {
        if (c.getCPF() == cpf) {
            clienteLogado = &c;
            print("Login realizado!\n");
            print("Pressione ENTER...");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            exibirMenu(); 
            return;
        }
    }

    print("CPF nao encontrado. \n");
    print("Pressione ENTER...");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}



