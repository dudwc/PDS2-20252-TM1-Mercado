#include "../include/Produto.hpp"

int main(){

    Produto macarrao = {"macarrao", "vilma", 8.50, 5892};

    std::cout << macarrao.getName() << std::endl << macarrao.getMarca() << std::endl << macarrao.getPreco() << std::endl;

    macarrao.alterarPreco();
    std::cout << macarrao.getPreco();
    return 0;
}