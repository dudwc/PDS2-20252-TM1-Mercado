#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Produto.hpp"



TEST_CASE("formatPreco formata com duas casas decimais"){

    CHECK(Produto::formatPreco(5.00) == "5.00");
    CHECK(Produto::formatPreco(10.998) == "11.00");
    CHECK(Produto::formatPreco(1.147) == "1.15");
}

TEST_CASE("Uso do setDisponivel"){
    
    Produto p("Cereal", 6.75, 123);

    //torna disponivel
    p.setDisponivel(true);
    CHECK(p.estaDisponivel() == true);

    //torna indisponivel
    p.setDisponivel(false);
    CHECK(p.estaDisponivel() == false);
}

TEST_CASE("Uso do set e get Preco"){
    
    Produto p("Cereal", 6.75, 123);

    p.setPreco(10.0);

    CHECK(p.getPreco() == 10.0);
}

TEST_CASE("Uso do set e get Peso da classe derivada"){
    
    FrutasEVerduras cenoura("Cenoura", 2.50, 100);

    //get do peso inicializado
    CHECK(cenoura.getPeso() == doctest::Approx(0.0));

    //definindo pes
    cenoura.setPeso(2.5);
    CHECK(cenoura.getPeso() == doctest::Approx(2.5));
}