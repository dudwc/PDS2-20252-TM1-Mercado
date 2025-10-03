#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>
#include <string>
#include "Produto.hpp"

class Caixa{
    private:
        std::string formaPagamento;
        int usuario;
        int valorTotal;
        std::vector <Produto> itensVenda;
    
    public:
        Caixa(std::string formaPagamento, int usuario, int valorTotal, std::vector <Produto> itensVenda) :
        formaPagamento(formaPagamento), usuario(usuario), valorTotal(valorTotal), itensVenda(itensVenda) {}
        ~Caixa(){};

        void RegistrarProduto(Produto p);
        bool RemoverItem(Produto p);
        int ExibirTotal() const;
        std::string  getFormaPagamento() const;
        int getUsuario() const;
};


#endif
