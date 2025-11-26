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
        std::string unidade;

    public:
        Produto(std::string nome, double preco, int id, std::string unidade = "U") : 
            nome(nome), preco(preco), id(id), disponivel(true), unidade(unidade) {}

        virtual std::string getUnidade() const;

        virtual ~Produto() {};

        static std::string formatPreco(double valor);

        std::string getName() const;
        double getPreco() const;
        int getID() const;
        bool estaDisponivel() const;

        void setName(std::string novoNome);
        void setPreco(double novoPreco);
        void setID(int novoID);
        void setDisponivel(bool disponivel);
        void setUnidade(std::string novaUnidade);

        void alterarPreco();
        bool operator<(const Produto& outro) const;
        


};

class FrutasEVerduras : public Produto{
    private:
        double peso;
    public:
        FrutasEVerduras(std::string nome, double preco, int id) :
            Produto(nome, preco, id, "KG") {}
       
        ~FrutasEVerduras() {};

        double getPeso() const;
        void setPeso(double novaPeso);

        double pesar();
};

#endif