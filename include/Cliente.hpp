#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Produto.hpp"
#include "Caixa.hpp"
#include "Estoque.hpp"

class Cliente{

private:
    int id;
    std::string nome;
    std::string formaPagamento;
    std::vector<Produto> carrinho;

    public:
        Cliente(int id, std::string nome);

        void escolherProduto(Estoque& estoque, int idProduto, int quantidade);
        void verificarPrecos(const Estoque& estoque) const;
        void escolherFormaPagamento(std::string forma);
        void finalizarCompra(Caixa& caixa);
        void receberAvisoPromocao(const std::string& mensagem);

        int getId() const;
        std::string getNome() const;
        std::string getFormaPagamento() const;

};

#endif
