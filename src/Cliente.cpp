#include "../include/Cliente.hpp"
#include <iostream>
#include <fstream> // pra lidar com arquivos
#include <iomanip> // formatação de valores monetários

Cliente::Cliente(const std::string& nome, const std::string& cpf)
    : nome(nome), cpf(cpf), totalGasto(0.0) {} // inicia com total gasto zerado

std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getCPF() const {
    return cpf;
}

double Cliente::getTotalGasto() const {
    return totalGasto;
}

void Cliente::registrarCompra(const std::string& descricao, double valor) {
    historicoCompras.push_back(descricao); // guarda a descrição da compra
    totalGasto += valor;                   // soma o valor ao total
}

void Cliente::mostrarHistorico() const {
    std::cout << "Histórico de compras de " << nome << ":\n";
    for (const auto& item : historicoCompras) {
        std::cout << "- " << item << "\n";
    }
    std::cout << "Total gasto: R$ " << std::fixed << std::setprecision(2) << totalGasto << "\n";
}

void Cliente::salvarHistorico() const {
    std::ofstream arquivo("historico_" + cpf + ".txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar histórico.\n";
        return;
    }

    arquivo << "Cliente: " << nome << " (" << cpf << ")\n";
    arquivo << "Compras:\n";
    for (const auto& item : historicoCompras) {
        arquivo << "- " << item << "\n";
    }
    arquivo << "Total gasto: " << totalGasto << "\n";
    arquivo.close();
}

void Cliente::carregarHistorico() {
    std::ifstream arquivo("historico_" + cpf + ".txt");
    if (!arquivo.is_open()) {
        std::cerr << "Nenhum histórico encontrado para este cliente.\n";
        return;
    }

    std::string linha;
    historicoCompras.clear(); // limpa histórico atual antes de carregar
    while (std::getline(arquivo, linha)) {
        if (linha.rfind("- ", 0) == 0) { // se a linha começar com "- ", é uma compra
            historicoCompras.push_back(linha.substr(2));
        }
    }
    arquivo.close();
}
