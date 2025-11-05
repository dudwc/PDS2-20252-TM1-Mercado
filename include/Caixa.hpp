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
        Estoque& estoque;//agregação, ref ao estoque compartilhado
        
        //carrinho: chave=ID do produto e valor=quantd
        std::map<int, double> carrinho;
    
    public:
        Caixa(std::string formaPagamento, int usuario, Estoque& estoque) :
        formaPagamento(formaPagamento), usuario(usuario), estoque(estoque) {}
        ~Caixa(){};
        //registrar produto no estoque
        bool CadastrarProduto(const Produto& p, int quantidade);

        //métodos de carrinho
        bool AdicionarItem(const Produto& p,double quantidade=1);//quantidade=1 ao passar somente o p como parametro, já entende que a qntd é um
        bool RemoverItem(const Produto& p,double quantidade=1);
        double ExibirTotal() const;
        void ExibirCarrinho() const;
        void GerarNotaFiscal() const;

        //métodos para acesso
        std::string  getFormaPagamento() const;
        int getUsuario() const;
};

#endif
