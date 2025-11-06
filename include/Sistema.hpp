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
    
    public:
        Sistema() {}
        ~Sistema() {}

        void iniciar();
        void exibirMenuPrincipal();
        void exibirLogo();
        void print(std::string texto);
};

#endif