#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <fstream>

class Produto{

    protected:
        std::string nome;
        double preco;
        int id;
        bool disponivel;

    public:
        Produto(std::string nome, double preco, int id) : 
            nome(nome), preco(preco), id(id), disponivel(true) {}
        ~Produto() {};

        static std::string formatPreco(double valor);

        std::string getName() const;
        double getPreco() const;
        int getID() const;
        bool estaDisponivel() const;

        void setName(std::string novoNome);
        void setPreco(double novoPreco);
        void setID(int novoID);
        void setDisponivel(bool disponivel);  

        void alterarPreco();

        bool operator<(const Produto& other) const {
            return id < other.id;
        }

};

class FrutasEVerduras : public Produto{
    private:
        double peso;
    public:
        FrutasEVerduras(std::string nome, double preco, int id) :
            Produto(nome, preco, id) {}
        ~FrutasEVerduras() {};

        double getPeso() const;
        void setPeso(double novaPeso);

        double pesar();
};

#endif