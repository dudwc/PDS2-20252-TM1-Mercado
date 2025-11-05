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
        
        //carrinho: chave=ID do produto e valor=quantd
        std::map<int, double> carrinho;
    
    public:
        Caixa(int usuario, Estoque &estoque, std::string formaPagamento = "");
        ~Caixa(){};

        bool CadastrarProduto(const Produto& p, int quantidade);

        
        bool AdicionarItem(const Produto& p,double quantidade=1);
        bool RemoverItem(const Produto& p,double quantidade=1);
        double ExibirTotal() const;
        void ExibirCarrinho() const;
        void GerarNotaFiscal() const;

        
        std::string  getFormaPagamento() const;
        int getUsuario() const;
};

#endif
