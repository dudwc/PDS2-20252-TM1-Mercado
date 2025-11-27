#include "../include/Caixa.hpp"
#include "../include/Estoque.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>


Caixa::Caixa(Estoque &estoque) : estoque(estoque) {}

bool Caixa::adicionarItem(const std::string &nome, double quantidade){
        if (quantidade <= 0){
                std::cerr << "Quantidade inválida.\n";
                return false;
        }
        const Produto* p = estoque.buscarNome(nome);
        if(p == nullptr){
                std::cerr << "Produto não encontrado.\n";
                return false;
        }
        int id = p->getID();
        //checando estoque:
        double qtdDisponivel = estoque.getQuantidade(id);

        if(qtdDisponivel <= 0){
                std::cerr << "Produto fora de estoque.\n";
                return false;
        }
        if(quantidade > qtdDisponivel){
                std::cout << "Quantidade indisponivel. Estoque atual:" << qtdDisponivel << "\n";
                return false;

        }
        if (carrinho.find(id) != carrinho.end()){ // verifica se já tem outras unidades no carrinho
                        carrinho[id] += quantidade;
                }else{
                        carrinho[id] = quantidade;
                }
                std::cout << "Item adicionado com sucesso.\n";
                return true;
}


bool Caixa::removerItem(const std::string &nome, double quantidade){
        if (quantidade <= 0){
                std::cerr << "Quantidade inválida.\n";
                return false;
        }
        const Produto* p =estoque.buscarNome(nome);
        if(p == nullptr){
                std::cerr << "Produto não encontrado./n";
                return false;
        }

        int id = p->getID();

        if (carrinho.find(id) == carrinho.end()){
                std::cerr << "Este produto não está no carrinho.\n";
                return false;
        }
        if (quantidade >= carrinho[id]){
                carrinho.erase(id);
        }else{
                carrinho[id] -= quantidade;
        }
        return true;
}

double Caixa::exibirTotal() const{
        double total = 0.0;
        for (auto it = carrinho.begin(); it != carrinho.end(); it++){
                int chave = it->first;         
                double quantidade = it->second; 
                const Produto *p = estoque.buscarID(chave);
                if (p != nullptr){
                        total += p->getPreco() * quantidade;
                }else{
                        std::cerr << "Produto com ID:" << chave << " não encontrado" << std::endl;
                }
        }
        return total;
}

void Caixa::exibirCarrinho() const{
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
                        std::cerr << "Produto com código " << chave << " não encontrado no estoque!" << std::endl;
                }
        }
}

double Caixa::calcularTroco(double valorPago) const{
        double total = exibirTotal();
        double troco = valorPago - total;
        return troco;
}

void Caixa::gerarNotaFiscal(const std::string& formaPagamento, double valorPago) const{
        std::cout << "=========================================\n";
        std::cout << "            MERCADO         \n";
        std::cout << "=========================================\n";
        std::cout << std::left << std::setw(20) << "PRODUTO"
                  << std::setw(10) << "QTD"
                  << std::setw(10) << "PRECO" << std::endl;
        std::cout << "-----------------------------------------\n";
        for (const auto &par : carrinho){
                int codigo = par.first;
                double quantidade = par.second; 
                const Produto* p = estoque.buscarID(codigo);
                        if (p != nullptr) {        
                        std::string nome = p->getName();
                        double preco = p->getPreco();
                        std::cout << std::left << std::setw(20) << nome 
                                  << std::setw(10) << std::fixed << std::setprecision(2)<< quantidade
                                  << "R$ " << std::fixed << std::setprecision(2)
                                  << preco * quantidade << std::endl;
                        }
        }
        std::cout << "-----------------------------------------\n";
        std::cout << std::setw(30)<< "TOTAL:"
                  << "R$ " << std::fixed << std::setprecision(2)
                  << exibirTotal() << std::endl;
        std::cout << std::setw(30)<< "FORMA DE PAGAMENTO: "<< formaPagamento << std::endl;
        if(formaPagamento == "dinheiro" || formaPagamento == "Dinheiro"){
                std::cout << std::setw(30)<< "VALOR PAGO:"<< "R$ " << valorPago << std::endl;
                std::cout << std::setw(30)<<"TROCO:"<< "R$ " << std::fixed << 
                std::setprecision(2)<< calcularTroco(valorPago) << std::endl;

        }
        std::cout << "=========================================\n";
        std::cout << "           VOLTE SEMPRE! :D              \n";
        std::cout << "=========================================\n";
}

void Caixa::finalizarCompra(const std::string& formaPagamento, double valorPago){

        if(formaPagamento == "dinheiro" || formaPagamento == "Dinheiro"){
                double troco = calcularTroco(valorPago);
                if(troco < 0){
                        std::cerr<< "Valor insuficiente\n";
                        return;
                }
        }
        for(const auto& par : carrinho){//atualizando estoque pós compras
                int id = par.first;
                double qtd = par.second;
                estoque.removerProduto(id, qtd);
        }
        gerarNotaFiscal(formaPagamento, valorPago);
        carrinho.clear();

}
