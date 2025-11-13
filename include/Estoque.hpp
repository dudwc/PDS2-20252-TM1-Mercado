#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <map>
#include <fstream>
#include "Produto.hpp"

class Estoque{
    private:
        std::map<Produto, int> produtos;
        std::fstream arquivo;
    public:
        Estoque();
        Estoque(const std::map<Produto, int>& produtos);
        ~Estoque() {};

        void adicionarProduto(const Produto& produto, int qtd);
        bool removerProduto(int id, int qtd);
        const Produto* buscarID(int id);
        const Produto* buscarNome(const std::string& nome);
        void listarProdutos() const;
};


#endif