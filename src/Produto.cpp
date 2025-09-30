#include "../include/Produto.hpp"

std::string Produto::getName() const{
    return nome;
}

std::string Produto::getMarca() const{
    return marca;
}

double Produto::getPreco() const{
    return preco;
}

int Produto::getID() const{
    return id;
}

bool Produto::estaDisponivel() const{
    return disponivel;
}

void Produto::alterarPreco(){
    std::cout << "Preco atual: " << preco << std::endl;
    double novoPreco;
    std::cout << "Insira o novo preco: ";
    std::cin >> novoPreco;
    preco = novoPreco;
    std::cout << "Operacao confirmada.\n";
}

void Produto::setDisponivel(bool disponivel){
    this->disponivel = disponivel;
}