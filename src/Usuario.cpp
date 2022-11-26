#include "../include/Usuario.hpp"

Usuario::Usuario()
{
    this->nome = "Jogador";
    this->vitorias = 0;
    this->derrotas = 0;
    this->baralhos = {};
}

Usuario::~Usuario()
{

}
Usuario::Usuario(std::string nome, int vitorias, int derrotas, std::vector<std::string> baralhos)
{
    this->nome = nome;
    this->vitorias = vitorias;
    this->derrotas = derrotas;
    this->baralhos = baralhos;
}

int Usuario::getVitorias()
{
    return this->vitorias;
}

int Usuario::getDerrotas()
{
    return this->derrotas;
}
void Usuario::setVitorias(int vitorias)
{
    this->vitorias = vitorias;
}
void Usuario::setDerrotas(int derrotas)
{
    this->derrotas = derrotas;
}
void Usuario::addVitoria()
{
    this->vitorias++;
}
void Usuario::addDerrota()
{
    this->derrotas++;
}
std::string Usuario::getNome()
{
    return this->nome;
}
std::vector<std::string> Usuario::getBaralhos()
{
    return this->baralhos;
}
void Usuario::setNome(std::string nome)
{
    this->nome = nome;
}
void Usuario::setBaralhos(std::vector<std::string> baralhos)
{
    this->baralhos = baralhos;
}
void Usuario::addBaralho(std::string baralho)
{
    this->baralhos.push_back(baralho);
}
std::string Usuario::toString()
{
    std::string retorno = "Nome: " + this->nome + "\n";
    retorno += "Vitorias: " + std::to_string(this->vitorias) + "\n";
    retorno += "Derrotas: " + std::to_string(this->derrotas) + "\n";
    retorno += "Baralhos: \n";
    for (int i = 0; i < this->baralhos.size(); i++)
    {
        retorno += this->baralhos[i] + "\n";
    }
    return retorno;
}
