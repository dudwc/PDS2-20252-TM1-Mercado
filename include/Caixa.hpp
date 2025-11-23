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
        Estoque& estoque;
        
        //carrinho: chave=ID do produto e valor=quantd
        std::map<int, double> carrinho;
    
    public:
        Caixa(Estoque &estoque);

        ~Caixa(){};
        
        void iniciarCompra();
        bool adicionarItem(const std::string &nome,double quantidade);
        bool removerItem(const std::string &nome,double quantidade);
        double exibirTotal() const;
        double calcularTroco(double valorPago) const;
        void exibirCarrinho() const;
        void gerarNotaFiscal(const std::string& formaPagamento, double valorPago = 0.0) const;
        void finalizarCompra(const std::string& formaPagamento, double valorPago = 0.0);
};

#endif
