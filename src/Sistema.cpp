#include "../include/Sistema.hpp"
#include <cstdlib>  // Para std::exit
#include <fstream>
#include <sstream>
int Sistema::proximoIDFuncionario = 3971;

Sistema::Sistema() {
    carregarProximoID();
    std::ifstream arquivoFuncionarios("arquivos/funcionarios.txt");
    //std::ifstream arquivoClientes("../arquivos/clientes.txt");
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

Sistema::~Sistema() {}

void Sistema::carregarProximoID() {
    std::ifstream arquivo("arquivos/proximoID.txt");
    if (arquivo.is_open()) {
        arquivo >> proximoIDFuncionario;
        arquivo.close();
    }
}

void Sistema::salvarProximoID() {
    std::ofstream arquivo("arquivos/proximoID.txt");
    if (arquivo.is_open()) {
        arquivo << proximoIDFuncionario;
        arquivo.close();
    }
}

void Sistema::print(std::string texto) {
    int delay_milliseconds = 1; // tempo de atraso entre cada caractere

    for (char c : texto) {
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
                exibirMenuPrincipal();
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

void Sistema::exibirMenuPrincipal(){
    int opcao;
    while(true) {
        system("cls");
        exibirLogo();
        print("\n--- Menu Principal ---\n");
        print("1. Login de funcionario\n");
        print("2. Cadastrar funcionario\n");
        print("3. Sair\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                system("cls");
                print("Login de funcionario.\n");
                loginFuncionario();
                std::cin >> opcao;
                break;
            case 2:
                system("cls");
                print("Cadastro de novo funcionario.\n");
                cadastrarFuncionario();
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

Funcionario* Sistema::cadastrarFuncionario(){
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
    
    return &funcionarios.back();
}


void Sistema::loginFuncionario(){
    std::string nome;
    int id;
    std::string senha;
    print("Nome: ");
    std::cin >> nome;
    print("ID: ");
    std::cin >> id;
    print("Senha: ");
    std::cin >> senha;
    bool status = verificarLogin(nome, id, senha);
    if(!status){
        for(auto& funcionario : funcionarios){
            if(funcionario.getNome() == nome && funcionario.getID() == id && funcionario.getSenha() == senha){
                funcionario.setLogado(true);
                return;
            }
        }
    }
}

bool Sistema::verificarLogin(const std::string& nome, const int id, const std::string& senha){
    for(const auto& funcionario : funcionarios){
        if(funcionario.getNome() == nome && funcionario.getID() == id && funcionario.getSenha() == senha){
            system("cls");
            print("Login bem sucedido! Bem-vinda(o), " + nome + ".\n");
            return true;
        }
    }
    print("Falha no login. Verifique suas credenciais.\n");
    return false;
}