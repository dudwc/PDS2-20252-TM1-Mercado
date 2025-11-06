#include "../include/Sistema.hpp"
#include <cstdlib>  // Para std::exit


void Sistema::print(std::string texto) {
    int delay_milliseconds = 1; // tempo de atraso entre cada caractere

    for (char c : texto) {
        std::cout << c << std::flush; // imprime caractere e limpa o buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_milliseconds)); // funcao de atraso
    }
}

void Sistema::iniciar(){
    int c;
   do {
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
                c = 2; 
                return;
            
            default:
                print("Opcao invalida. Tente novamente.\n");
                break;
        }
            
        } while(c!=2);
}

void Sistema::exibirLogo(){
    std::ifstream entrada("d:/UFMG/PDS/supermercado/mercado.txt");
            if (!entrada.is_open()) {
                std::cout << "Erro ao abrir o arquivo para leitura." << std::endl;
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
        print("1. Gerenciar Estoque\n");
        print("2. Operacoes de Caixa\n");
        print("3. Sair\n");
        print("Escolha uma opcao: ");
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                system("cls");
                print("Funcionalidade de Gerenciar Estoque ainda nao implementada.\n");
                print("1. Voltar\n");
                print("Escolha uma opcao: ");
                std::cin >> opcao;
                break;
            case 2:
                system("cls");
                print("Funcionalidade de Operacoes de Caixa ainda nao implementada.\n");
                print("1. Voltar\n");
                print("Escolha uma opcao: ");
                std::cin >> opcao;
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