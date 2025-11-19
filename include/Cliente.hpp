#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include <vector>

class Cliente {
private:
    std::string nome;
    std::string cpf;
    double totalGasto;
    std::vector<std::string> historicoCompras; // guarda descrições das compras feitas pelo cliente

public:
    // construtor básico: cria um cliente com nome e CPF
    Cliente(const std::string& nome, const std::string& cpf);

    // adcionar os getters para retornarem os dados do cliente
    std::string getNome() const;
    std::string getCPF() const;
    double getTotalGasto() const;

    // adiciona uma nova compra ao histórico e soma ao total gasto
    void registrarCompra(const std::string& descricao, double valor);

    // mostra as compras realizadas até o momento
    void mostrarHistorico() const;

    // salva e carrega histórico em arquivo (simula persistência de dados)
    void salvarHistorico() const;
    void carregarHistorico();
};

#endif
