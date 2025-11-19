#include "../include/Sistema.hpp"
#include <cstdlib>  // Para std::exit
#include <fstream>
#include <sstream>
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
                print("1. Voltar.\n");
                print("Escolha uma opcao: ");
                std::cin >> opcao;
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
    print("Pressione 1 para continuar: ");
    int i;
    std::cin >> i;
    
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

SistemaCliente::SistemaCliente() { /*std::ifstream arquivoClientes("../arquivos/clientes.txt");*/ }

SistemaCliente::~SistemaCliente() {}

void SistemaCliente::iniciar() {
    int opcao;
    while(true) {
        system("cls");
        print("1. Fazer login.\n");
        print("2. Fazer cadastro.\n");
        print("3. Voltar ao menu principal.\n");
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
        print("--- Menu de Cliente ---\n");
        print("1. Fazer compras\n");
        print("2. Ver historico de compras\n");
        print("3. Sair\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                system("cls");
                print("Sistema em manutencao\n");
                print("Pressione 1 para continuar: ");
                std::cin >> opcao;
                break;
            case 2:
                system("cls");
                print("Sistema em manutencao\n");
                print("Pressione 1 para continuar: ");
                std::cin >> opcao;
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

Cliente* SistemaCliente::cadastrarCliente(){
    print("Sistema em manutencao.\n");
    print("Pressione 1 para continuar: ");
    int i;
    std::cin >> i;
    return nullptr;
}

void SistemaCliente::loginCliente(){
    print("Sistema em manutencao.\n");
    print("Pressione 1 para continuar: ");
    int i;
    std::cin >> i;
}