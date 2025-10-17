#include "../include/Caixa.hpp"
#include "../include/Estoque.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>


Caixa::Caixa(std::string formaPagamento, int usuario,Estoque& estoque):formaPagamento(formaPagamento),usuario(usuario),estoque(estoque){}

bool Caixa::CadastrarProduto(const Produto& p, int quantidade){
        if (this->usuario != 1) {
                std::cout << "Apenas funcionários podem cadastrar novos produtos.\n"; 
                return false;
        }else{
                if(quantidade <= 0){
                        std::cout<<"Erro: quantidade inadequada.\n"<< std::endl;
                        return false;
                }else{
                        estoque.adicionarProduto(p, quantidade);
                        return true;
                }
        } 
}

bool Caixa::AdicionarItem(const Produto& p, double quantidade){
        if(quantidade <=0){
                std::cout<<"Quantidade inválida.\n";
                return false;
        }
        if(carrinho.contains(p.getID())){
                carrinho[p.getID()] +=quantidade;
        }else{
                carrinho[p.getID()] =quantidade;
        }
        return true;
}
bool Caixa::RemoverItem(const Produto& p,double quantidade){
        if(!carrinho.contains(p.getID())){return false;}
        if(quantidade >= carrinho[p.getID()]){
                carrinho.erase(p.getID());
        }else{
                carrinho[p.getID()] -= quantidade;
        }
        return true;
}
int Caixa::ExibirTotal() const{
        int total=0;
        for ( auto it = carrinho.begin(); it != carrinho.end(); it++){
                int chave = it->first;
                int quantidade = it->second;
                const Produto* p = estoque.buscarProduto(chave);
                if(p != nullptr){
                        total += p->getPreco()*quantidade;
                }else{
                        std::cout<<"Produto com ID:"<< chave << " não encontrado"<< std::endl;
                }
                
        }
        return total;      
}
std::string  Caixa::getFormaPagamento() const{
        return formaPagamento;
}
int Caixa::getUsuario() const{
        return usuario;
}
