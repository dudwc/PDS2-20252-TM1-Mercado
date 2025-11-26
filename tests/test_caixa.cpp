
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Caixa.hpp"
#include "Estoque.hpp"
#include "Produto.hpp"

TEST_CASE("adicionarItem falha com quantidade negativa"){
    Produto leite("Leite", 6.30, 103);

    std::map<Produto,double> est = {{leite, 8}};
    Estoque estoque(est);

    Caixa caixa(estoque);

    CHECK(caixa.adicionarItem("Leite", -2) == false);
}

TEST_CASE("adicionarItem adiciona produto no carrinho"){
    Produto biscoito("Biscoito", 2.50, 101);

    std::map<Produto,double> est = {{biscoito, 3}};
    Estoque estoque(est);

    Caixa caixa(estoque);

    CHECK(caixa.adicionarItem("Biscoito", 1) == true);
}

TEST_CASE("adicionarItem tenta adicionar quantidade indisponivel"){
    Produto detergente("DetergenteYpe", 2.50, 101);

    std::map<Produto,double> est = {{detergente, 10}};
    Estoque estoque(est);

    Caixa caixa(estoque);

    CHECK(caixa.adicionarItem("DetergenteYpe", 15) == false);
}

TEST_CASE("calcularTroco"){
    Produto bolo("Bolo", 8.50, 108);

    std::map<Produto,double> est = {{bolo, 8}};
    Estoque estoque(est);

    Caixa caixa(estoque);
    caixa.adicionarItem("Bolo", 3);

    CHECK(caixa.calcularTroco(30.0) == doctest::Approx(4.5));
}

TEST_CASE("removerItem remove quantidade de produto do carrinho"){
    Produto sabonete("Sabonete", 6.99, 123);
    Produto bolo("Bolo", 8.50, 108);

    std::map<Produto,double> est = {
        {sabonete, 25},
        {bolo, 8}
    };

    Estoque estoque(est);
    Caixa caixa(estoque);

    caixa.adicionarItem("Sabonete", 6);

    CHECK(caixa.removerItem("Sabonete", 3) == true);
    CHECK(caixa.removerItem("Bolo", 2) == false);
}
