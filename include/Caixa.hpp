#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Produto.hpp"
#include "Estoque.hpp"

class Caixa{
    private:
        std::string formaPagamento;
        int usuario;
        Estoque& estoque;
        
        //carrinho: chave=ID do produto e valor=quantidade
        std::map<int, int> carrinho;
    
    public:
        Caixa(std::string formaPagamento, int usuario, Estoque& estoque) :
        formaPagamento(formaPagamento), usuario(usuario), estoque(estoque) {}
        ~Caixa(){};

        
        bool CadastrarProduto(const Produto& p, int quantidade);

        
        bool AdicionarItem(const Produto& p,double quantidade=1);//quantidade=1 ao passar somente o p como parametro, já entende que a quantidade é um
        bool RemoverItem(const Produto& p,double quantidade=1);
        int ExibirTotal() const;

        
        std::string  getFormaPagamento() const;
        int getUsuario() const;
};

#endif
