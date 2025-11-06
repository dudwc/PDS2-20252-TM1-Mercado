#include "../include/Funcionario.hpp"

Funcionario::Funcionario(std::string nome, int id, std::string senha)
    : nome(nome), id(id), senha(senha) {}

std::string Funcionario::getNome() const {
    return nome;
}

int Funcionario::getID() const {
    return id;
}

std::string Funcionario::getSenha() const {
    return senha;
}

void Funcionario::setNome(std::string novoNome) {
    nome = novoNome;
}

void Funcionario::setID(int novoID) {
    id = novoID;
}

void Funcionario::setSenha(std::string novaSenha) {
    senha = novaSenha;
}