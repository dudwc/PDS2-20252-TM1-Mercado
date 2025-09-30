#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <fstream>

class Produto{

    protected:
        std::string nome, marca;
        double preco;
        int id;
        bool disponivel;

    public:
        Produto(std::string nome, std::string marca, double preco, int id) : 
            nome(nome), marca(marca), preco(preco), id(id), disponivel(true) {}
        ~Produto() {};

        std::string getName() const;
        std::string getMarca() const;
        double getPreco() const;
        int getID() const;
        bool estaDisponivel() const;
        
        void alterarPreco();
        void setDisponivel(bool disponivel);

};

#endif 