#include "../include/Caixa.hpp"
#include "../include/Estoque.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>


Caixa::Caixa(int usuario, Estoque &estoque, std::string formaPagamento)
    : formaPagamento(formaPagamento), usuario(usuario), estoque(estoque) {}


std::string Caixa::getFormaPagamento() const{
        return formaPagamento;
}
int Caixa::getUsuario() const{
        return usuario;
}
bool Caixa::CadastrarProduto(const Produto &p, int quantidade){
        if (this->usuario != 1){
                std::cout << "Apenas funcionários podem cadastrar novos produtos\n";
                return false;
        }else{
                if (quantidade <= 0){
                        std::cout << "Erro: quantidade inadequada" << std::endl;
                        return false;
                }else{
                        estoque.adicionarProduto(p, quantidade);
                        return true;
                }
        }
}
bool Caixa::AdicionarItem(const Produto &p, double quantidade){
        if (quantidade <= 0){
                std::cout << "Quantidade inválida.\n";
                return false;
        }
        if (carrinho.find(p.getID()) != carrinho.end()){ 
                carrinho[p.getID()] += quantidade;
        }else{
                carrinho[p.getID()] = quantidade;
        }
        return true;
}
bool Caixa::RemoverItem(const Produto &p, double quantidade){
        if (carrinho.find(p.getID()) == carrinho.end()){
                return false;
        }
        if (quantidade >= carrinho[p.getID()]){
                carrinho.erase(p.getID());
        }else{
                carrinho[p.getID()] -= quantidade;
        }
        return true;
}
double Caixa::ExibirTotal() const{
        double total = 0.0;
        for (auto it = carrinho.begin(); it != carrinho.end(); it++){
                int chave = it->first;         
                double quantidade = it->second; 
                const Produto *p = estoque.buscarID(chave);
                if (p != nullptr){
                        total += p->getPreco() * quantidade;
                }else{
                        std::cout << "Produto com ID:" << chave << " não encontrado" << std::endl;
                }
        }
        return total;
}
void Caixa::ExibirCarrinho() const{
        if (carrinho.empty()){
                std::cout << "Carrinho vazio.\n";
                return;
        }
        std::cout << std::left << std::setw(20) << "ITEM" << "QUANTIDADE" << std::endl;
        for (const auto &par : carrinho){
                int chave = par.first;
                const Produto *p = estoque.buscarID(chave);
                if (p != nullptr){
                        std::cout << std::left << std::setw(20) << p->getName() << par.second << std::endl;
                }else{
                        std::cout << "Produto com código " << chave << " não encontrado no estoque!" << std::endl;
                }
        }
}
void Caixa::GerarNotaFiscal() const{
        std::cout << "=========================================\n";
        std::cout << "            SUPERTOP          \n";
        std::cout << "=========================================\n";
        std::cout << std::left << std::setw(20) << "PRODUTO"
                  << std::setw(10) << "QTD"
                  << std::setw(10) << "PREÇO" << std::endl;
        std::cout << "-----------------------------------------\n";
        for (const auto &par : carrinho){
                int codigo = par.first;
                double quantidade = par.second; 
                const Produto* p = estoque.buscarID(codigo);
                        if (p != nullptr) {        
                        std::string nome = p->getName();
                        double preco = p->getPreco();
                        std::cout << std::left << std::setw(20) << nome << std::setw(10) << quantidade
                                  << "R$ " << std::fixed << std::setprecision(2)
                                  << preco * quantidade << std::endl;
                        }
        }
        std::cout << "-----------------------------------------\n";
        std::cout << std::setw(30) << "TOTAL:"
                  << "R$ " << std::fixed << std::setprecision(2)
                  << ExibirTotal() << std::endl;
        std::cout << "FORMA DE PAGAMENTO: " << formaPagamento << std::endl;
        std::cout << "=========================================\n";
        std::cout << "           VOLTE SEMPRE! :D              \n";
        std::cout << "=========================================\n";
}
