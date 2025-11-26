#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Cliente.hpp"


// ---- Teste do Construtor ---- 
TEST_CASE("Cliente - construtor e getters básicos") {
    Cliente c("Bruna", "98765432109");

    CHECK(c.getNome() == "Bruna");
    CHECK(c.getCPF() == "98765432109");
    CHECK(c.getTotalGasto() == 0.0);
}

// ---- Teste do Método ----
TEST_CASE("Cliente - registrarCompra acumula valor corretamente") {
    Cliente c("Bruna", "500");
    c.registrarCompra("Banana", 5.99);
    c.registrarCompra("Maca", 3.49);

    CHECK(c.getTotalGasto() == doctest::Approx(9.48));
}

// ---- Teste do Historico ----
TEST_CASE("Cliente - mostrarHistorico não deve lançar exceções"){
    Cliente c("Bruna", "98765432109");
    c.registrarCompra("Maca", 3.49);

    CHECK_NOTHROW(c.salvarHistorico()); // salva em arquivo
    Cliente c2("Teste","1548976523486"); // cria outro cliente com mesmo CPF para carregar

    CHECK_NOTHROW(c2.carregarHistorico());
}
