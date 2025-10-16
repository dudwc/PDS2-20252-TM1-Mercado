#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Produto.hpp"


class Cliente{

private:
    std::string nome;
    std::string cpf;
    std::vector<Produto> historicoCompras;


public:
    Cliente(std::string nome = "", std::string cpf = "");
    
    std::string getNome() const;
    std::string getCPF() const;

    void adicionarCompra(const Produto& produto);
    void mostrarHistorico() const;
    void salvarEmAquivo();
    void carregarDeArquivo();

};

#endif
