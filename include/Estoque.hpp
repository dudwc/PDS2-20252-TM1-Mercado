#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <chrono>
#include <thread>
#include <iostream>
#include <map>
#include <fstream>
#include "Produto.hpp"

class Estoque{
    private:
        std::map<Produto, double> produtos;
        std::fstream arquivo;
    public:
        Estoque();
        Estoque(const std::map<Produto, double>& produtos);
        ~Estoque() {};

        void print(std::string texto);
        void adicionarProduto(const Produto& produto, double qtd);
        bool removerProduto(int id, double qtd);
        const Produto* buscarID(int id);
        const Produto* buscarNome(const std::string& nome);
        void listarProdutos() const;
        std::map<Produto, double> getProdutos() const;
        double getQuantidade(int id) const;
};

#endif
