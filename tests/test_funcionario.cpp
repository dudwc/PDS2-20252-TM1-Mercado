#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Funcionario.hpp"


TEST_CASE("Construtor inicializa nome corretamente"){
    
    Funcionario f("Mordecai", 2018, "seiscincoum");

    CHECK(f.getSenha() == "seiscincoum");
}

TEST_CASE("Uso do setNome"){
    
    Funcionario f("Mordecai", 2018, "seiscincoum");
    f.setNome("Rigby");

    CHECK(f.getNome() == "Rigby");
}

TEST_CASE("setLogado altera o estado de login "){
    
    Funcionario f("Mordecai", 2018, "seiscincoum");
    //esperando login-inicial
    CHECK(f.isLogado() == false);

    //logando
    f.setLogado(true);
    CHECK(f.isLogado() == true);

    //deslogando
    f.setLogado(false);
    CHECK(f.isLogado() == false);
}


