#include "../include/Produto.hpp"
#include "../include/Estoque.hpp"

int main(){

    Estoque estoque;
    Produto banana("Banana", 5.99, 1);
    Produto maca("Maca", 3.49, 2);
    estoque.listarProdutos();

    estoque.adicionarProduto(banana, 10);
    estoque.adicionarProduto(maca, 20);
    estoque.listarProdutos();

    estoque.removerProduto(1, 5);
    estoque.listarProdutos();

    const Produto* produto = estoque.buscarProduto(2);
    if (produto) {
        std::cout << "Produto encontrado: " << produto->getName() 
                  << " - Preco: " << Produto::formatPreco(produto->getPreco()) 
                  << std::endl;
    } else {
        std::cout << "Produto nao encontrado." << std::endl;
    }

    estoque.adicionarProduto(banana, 3);
    estoque.listarProdutos();

    

    return 0;

}