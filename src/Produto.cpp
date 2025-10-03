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

void Produto::setName(std::string novoNome){
    nome = novoNome;
}

void Produto::setMarca(std::string novaMarca){
    marca = novaMarca;
}

void Produto::setPreco(double novoPreco){
    preco = novoPreco;
}

void Produto::setID(int novoID){
    id = novoID;
}

void Produto::setDisponivel(bool disponivel){ 
    this->disponivel = disponivel;
}

void Produto::alterarPreco(){
    std::cout << "Preco atual: " << preco << std::endl;
    double novoPreco;
    std::cout << "Insira o novo preco: ";
    std::cin >> novoPreco;
    preco = novoPreco;
    std::cout << "Operacao confirmada.\n";
}
