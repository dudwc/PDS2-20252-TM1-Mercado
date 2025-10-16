#include "../include/Cliente.hpp"
#include<iostream>
#include<iomanip>
#include<sstream>



Cliente::Cliente(std::string nome, std::string cpf)
    : nome(nome), cpf(cpf) {}

std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getCPF() const {
    return cpf;
}

void::string Cliente::adicionarCompra(const Produto& produto) {
    historicoCompras.push_back(produto);
}

void Cliente::mostrarHistorico() const {
    std::cout << "\nHistótico de compras de " << nome " (" << cpf << "):\n";

    if(historicoCompras.empty()) {
        std::cout << "Nenhuma compra registrada.\n";
        return;
    }

    for (const auto& produto : historicoCompras) {
        std::cout << "- " << produto.getNome()
                  << " | Preço R$ " << Produto::formatPreco(produto.getPreco())
                  << std::endl;
    }
}
