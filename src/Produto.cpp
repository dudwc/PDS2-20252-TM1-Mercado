#include "../include/Produto.hpp"
#include <iomanip>
#include <sstream>

std::string Produto::formatPreco(double valor){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << valor;
    return oss.str();
}

std::string Produto::getUnidade() const {
    return unidade;
}

std::string Produto::getName() const{
    return nome;
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
    std::cout << "Preco atual: " << formatPreco(preco) << std::endl;
    double novoPreco;
    std::cout << "Insira o novo preco: ";
    std::cin >> novoPreco;
    preco = novoPreco;
    std::cout << "Operacao confirmada.\n";
}

bool Produto::operator<(const Produto& outro) const {
    return this->nome < outro.nome;
}


//============================= FrutasEVerduras ============================//

double FrutasEVerduras::getPeso() const{
    return peso;
}

void FrutasEVerduras::setPeso(double novaPeso){
    peso = novaPeso;
}

double FrutasEVerduras::pesar() {
    double peso;
    std::cout << "Insira o peso do produto em Kg: ";
    std::cin >> peso;
    this->setPeso(peso);
    std::cout << peso << " Kg de " << nome << " por R$" << formatPreco(preco * peso) << std::endl;
    return peso * preco;
}