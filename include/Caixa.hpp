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
        
        bool cadastrarProduto(const Produto& p, int quantidade);

        bool adicionarItem(const Produto& p,double quantidade=1);
        bool removerItem(const Produto& p,double quantidade=1);
        double exibirTotal() const;
        double calcularTroco(double valorPago) const;
        void exibirCarrinho() const;
        void gerarNotaFiscal(double valorPago = 0.0) const;

        std::string  getFormaPagamento() const;
        int getUsuario() const;
};

#endif
