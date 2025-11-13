#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include "Funcionario.hpp"
#include "Estoque.hpp"
#include "Produto.hpp"
#include "Caixa.hpp"
#include "Cliente.hpp"

class Sistema {
    private:
        Estoque estoque;
        std::fstream arquivo;
        std::vector<Funcionario> funcionarios;
        static int proximoIDFuncionario;  // Rastreia o próximo ID a ser atribuído
    
    public:
    Sistema();
    ~Sistema();

        void iniciar();
        void exibirMenuPrincipal();
        void exibirLogo();
        void print(std::string texto);
        Funcionario* cadastrarFuncionario();
        void loginFuncionario();
        bool verificarLogin(const std::string & usuario, const int id, const std::string& senha);
        void carregarProximoID();
        void salvarProximoID();
};
#endif