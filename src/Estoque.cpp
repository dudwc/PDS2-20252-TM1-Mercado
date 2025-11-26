#include "..\include\Estoque.hpp"
#include <iomanip>
#include <sstream>

Estoque::Estoque(){
    arquivo.open("arquivos/estoque.txt", std::ios::in);
    if (!arquivo.is_open()) {
        print("Erro ao abrir o arquivo de estoque.");
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        int id;
        std::string nome;
        double preco;
        double quantidade;
        std::string unidade;

        if (!(iss >> id >> nome >> preco >> quantidade >> unidade)) {
            print("Erro ao ler a linha do arquivo: " + linha + "\n");
            continue; // Pula para a próxima linha em caso de erro
        }

        if (unidade == "KG") {
            FrutasEVerduras* produto = new FrutasEVerduras(nome, preco, id);
            produtos[produto] = quantidade;
        } else {
            Produto* produto = new Produto(nome, preco, id, unidade);
            produtos[produto] = quantidade;
        }
    }
    arquivo.close();
}

Estoque::Estoque(const std::map<Produto*, double>& produtos) : 
    produtos(produtos) {
    arquivo.open("arquivos/estoque.txt", std::ios::out | std::ios::trunc);
    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo de estoque para escrita." << std::endl;
        return;
    }

    for (const auto& pair : produtos) {
        Produto* produto = pair.first;
        double quantidade = pair.second;
        
        arquivo << produto->getID() << " " 
                << produto->getName() << " " 
                << std::fixed << std::setprecision(2) << produto->getPreco() << " ";
        
        if(produto->getUnidade() == "KG"){
            arquivo << std::fixed << std::setprecision(2) << quantidade << " ";
        } else {
            arquivo << static_cast<int>(quantidade) << " ";
        }
        arquivo << produto->getUnidade() << std::endl;
    }
    arquivo.close();
}

Estoque::~Estoque() {
    for (auto& pair : produtos) {
        delete pair.first;
    }
    produtos.clear();
}

void Estoque::print(std::string texto) {
    int delay_milliseconds = 1; // tempo de atraso entre cada caractere

    for (char c : texto) {
        std::cout << c << std::flush; // imprime caractere e limpa o buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_milliseconds)); // funcao de atraso
    }
}

void Estoque::adicionarProduto(Produto* produto, double qtd) {
    for (auto& pair : produtos) {
        if (pair.first->getID() == produto->getID()) {
            pair.second += qtd;
            
            // Atualiza arquivo
            arquivo.open("arquivos/estoque.txt", std::ios::out | std::ios::trunc);
            if (!arquivo.is_open()) {
                std::cout << "Erro ao abrir o arquivo." << std::endl;
                return;
            }

            for (const auto& p : produtos) {
                arquivo << p.first->getID() << " " 
                        << p.first->getName() << " " 
                        << std::fixed << std::setprecision(2) << p.first->getPreco() << " "
                        << p.second << " " << p.first->getUnidade()
                        << std::endl;
            }
            arquivo.close();
            return;
        }
    }
    
    produtos[produto] = qtd;
    
    arquivo.open("arquivos/estoque.txt", std::ios::out | std::ios::trunc);
    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    for (const auto& p : produtos) {
        arquivo << p.first->getID() << " " 
                << p.first->getName() << " " 
                << std::fixed << std::setprecision(2) << p.first->getPreco() << " "
                << p.second << " " << p.first->getUnidade()
                << std::endl;
    }
    arquivo.close();
}
    

bool Estoque::removerProduto(int id, double qtd){
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->first->getID() == id) {
            if (it->second >= qtd) {
                it->second -= qtd;
                if (it->second == 0) {
                    delete it->first;
                    produtos.erase(it);
                }
                
                arquivo.open("arquivos/estoque.txt", std::ios::out | std::ios::trunc);
                if (!arquivo.is_open()) {
                    std::cout << "Erro ao abrir o arquivo." << std::endl;
                    return false;
                }

                for (const auto& p : produtos) {
                    arquivo << p.first->getID() << " " 
                            << p.first->getName() << " " 
                            << std::fixed << std::setprecision(2) << p.first->getPreco() << " "
                            << p.second << " " << p.first->getUnidade()
                            << std::endl;
                }
                arquivo.close();
                return true;
            } else {
                print("Quantidade insuficiente em estoque.");
                return false;
            }
        }
    }
    print("Produto com ID " + std::to_string(id) + " nao encontrado.\n");
    return false;
}

const Produto* Estoque::buscarID(int id){
    for (const auto& pair : produtos) {
        if (pair.first->getID() == id) { 
            return pair.first;
        }
    }
    return nullptr;
}

const Produto* Estoque::buscarNome(const std::string& nome){
    for (const auto& pair : produtos){
        if (pair.first->getName() == nome){
            return pair.first;
        }
    }
    return nullptr;
}

void Estoque::listarProdutos(){
    print("----- Produtos no Estoque -----\n");
    for (const auto& pair : produtos) {
        Produto* produto = pair.first; // Agora é ponteiro
        double quantidade = pair.second;
        std::cout << produto->getName()  // Agora usa ->
                  << "\t//\tPreco: " << Produto::formatPreco(produto->getPreco()) 
                  << "\t//\tQuantidade: " << quantidade << " " << produto->getUnidade()
                  << "\t//\tID: " << produto->getID()
                  << std::endl;
    }
}

std::map<Produto*, double> Estoque::getProdutos() const{
    return produtos;
}

double Estoque::getQuantidade(int id) const{
    for(const auto& pair : produtos){
        if(pair.first->getID() == id){ // Agora usa ->
            return pair.second;
        }
    }
    return -1;
}