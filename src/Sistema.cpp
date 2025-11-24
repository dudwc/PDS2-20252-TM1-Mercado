#include "../include/Sistema.hpp"
#include <cstdlib>  // Para std::exit
#include <fstream>
#include <sstream>
#include "Sistema.hpp"
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
    for (char c : ".......................................\n") {
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

    /*while(std::getline(arquivoClientes, linha)) {
        // Implementar leitura de clientes
    }*/
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
                print("Sistema em manutencao\n");
                print("Pressione ENTER para voltar.");
                std::cin.ignore();
                std::cin.get();
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

SistemaCliente::SistemaCliente() {
    std::ifstream arquivo("../arquivos/clientes.txt");
    if (!arquivo.is_open()) {
        print("Nenhum arquivo de clientes encontrado. Criando um novo... \n");
        return;
    }

    std::string linha;
    std::string nome, cpf;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);

        if(!(iss >> nome >> cpf)) {
            print("Falha ao ler cliente: " + linha + "\n");
            continue;
        }

        clientes.emplace_back(nome, cpf);
    }

    arquivo.close();
}

SistemaCliente::~SistemaCliente() {
    std::ofstream arquivo("../arquivos/clientes.txt", std::ios::trunc);

    if (!arquivo.is_open()) {
        print("Erro ao salvar clientes no arquivo. \n");
        return;
    }

    for (auto& c : clientes) {
        arquivo << c.getNome() << " " << c.getCPF() << "\n";
    }
    arquivo.close();
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
                return;
            default:
                system("cls");
                print("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
}

void SistemaCliente::exibirMenu() {
    int opcao;
    while(true) {
        system("cls");
        print("--- Menu do Cliente ---\n");
        print("1. Fazer compras\n");
        print("2. Ver historico de compras\n");
        print("3. Sair\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                system("cls");
                print("Sistema de compras em manutencao.\n");
                print("Pressione ENTER para voltar.");
                std::cin.ignore();
                std::cin.get();
                break;
            case 2:
                system("cls");
                print("Sistema de histórico em manutencao.\n");
                print("Pressione ENTER para voltar. ");
                std::cin.ignore();
                std::cin.get();
                break;
            case 3:
                system("cls");
                print("Saindo...\n");
                carregar();
                return;
            default:
                system("cls");
                print("Opcao invalida. \n");
                break;
        }
    }
}

Cliente* SistemaCliente::cadastrarCliente() {
    std::string nome, cpf;

    print("----- Cadastro de Cliente -----");
    print("Digite o nome: ");
    std::cin >> nome;

    print("Digite o CPF: ");
    std::cin >> cpf;

    if (verificarLogin(cpf)) { // verificar se o login existe no sistema
        print("Ja existe um cliente com esse CPF! \n");
        print("Pressione ENTER para continuar...");
        std::cin.ignore();
        std::cin.get();
        return nullptr;
    }

    clientes.emplace_back(nome, cpf);

    print ("Cliente cadastrado com sucesso!\n");
    print ("Pressione ENTER para continuar...");
    std::cin.ignore();
    std::cin.get();

    return &clientes.back();
}

bool SistemaCliente::verificarLogin(const std::string& cpf) {
    for (auto& c : clientes) {
        if (c.getCPF() == cpf) {
            return true;
        }
    }
    return false;
}

void SistemaCliente::loginCliente(){
    std::string cpf;
    print("---- Login do Cliente ----\n");
    print("Digite seu CPF: ");
    std:: cin >> cpf;

    if (verificarLogin(cpf)) {
        print("Login realizado!\n");
        print("Pressione ENTER para continuar...");
        std::cin.ignore();
        std::cin.get();

        exibirMenu(); // leva ao menu do cliente
    
    }else{
        print("CPF nao encontrado. \n");
        print("Pressione ENTER para continuar...");
        std::cin.ignore();
        std::cin.get();
    }
}


