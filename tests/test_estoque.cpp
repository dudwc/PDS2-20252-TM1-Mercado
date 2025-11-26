#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Estoque.hpp"
#include "Produto.hpp"

TEST_CASE("adicionarProduto adiciona ao estoque e soma quantidades corretamente") {

    Produto p("Leite", 6.30, 103);

    // estoque inicia com 5 caixas de leite
    std::map<Produto, double> est = { {p, 5.0} };
    Estoque estoque(est);

    // conferindo quantidade inicial
    CHECK(estoque.getQuantidade(103) == doctest::Approx(5.0));

    SUBCASE("Aumentando estoque de produto existente") {
        estoque.adicionarProduto(p, 20);
        CHECK(estoque.getQuantidade(103) == doctest::Approx(25.0));
    }
}

TEST_CASE("removerProduto remove quantidades e atualiza estoque") {

    Produto p("escova", 15.0, 125);

    std::map<Produto, double> est = { {p, 20.0} };
    Estoque estoque(est);

    bool confereremocao = estoque.removerProduto(125, 10);

    CHECK(confereremocao == true);
    CHECK(estoque.getQuantidade(125) == doctest::Approx(10.0));
}

TEST_CASE("buscarID retornando um obj de Produto") {

    Produto chinelo("Chinelo", 30.0, 115);
    Produto cafe("Cafe", 45.0, 130);

    std::map<Produto, double> est = { 
        {chinelo, 15.0},
        {cafe, 30.0}
    };
    Estoque estoque(est);

    const Produto* p = estoque.buscarID(130);

    REQUIRE(p != nullptr);//se falhar para a execução do teste(REQUIRE)
    CHECK(p->getName() == "Cafe");
    CHECK(p->getPreco() == doctest::Approx(45.00));
    CHECK(p->getID() == 130);
}




