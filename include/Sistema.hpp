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
    protected:
        Estoque estoque;
        std::fstream arquivo;
    
    public:
    Sistema();
    ~Sistema();

        virtual void iniciar();
        virtual void exibirMenu();
        void exibirLogo();
        void print(std::string texto);
        void carregar();
        
};

class SistemaFuncionario : public Sistema {
    private:
        std::vector<Funcionario> funcionarios;
        static int proximoIDFuncionario;  // Rastreia o próximo ID a ser atribuído
    
    public:
        SistemaFuncionario();
        ~SistemaFuncionario();

        void iniciar() override;
        void exibirMenu() override;
        Funcionario* cadastrarFuncionario();
        void loginFuncionario();
        bool verificarLogin(const int id, const std::string& senha);
        void carregarProximoID();
        void salvarProximoID();
};

class SistemaCliente : public Sistema {
    private:
        std::vector<Cliente> clientes; // lista de clientes armazenados no sistema

    public:
        SistemaCliente();
        ~SistemaCliente();

        void iniciar() override;
        void exibirMenu() override;

        Cliente* cadastrarCliente();
        void loginCliente(); // logar usando o CPF
        bool verificarLogin(const std::string& cpf); // checa se o CPF existe
        
};

#endif 


