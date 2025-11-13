#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>

class Funcionario{

    private:
        std::string nome;
        int id;
        std::string senha;
        bool logado = false;

    public:
        Funcionario(std::string nome, int id, std::string senha);
        ~Funcionario();

        std::string getNome() const;
        int getID() const;
        std::string getSenha() const;
        bool isLogado() const;

        void setNome(std::string novoNome);
        void setID(int novoID);
        void setSenha(std::string novaSenha);
        void setLogado(bool logado);

};

#endif